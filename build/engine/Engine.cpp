#include "Engine.h"

#include <iostream>
#include <thread>
#include <array>

#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_ttf.h>

//#include "../../sdl_utils/Texture.h"
#include "../../utils/thread/ThreadUtils.h"
#include "../../sdl_utils/time/Time.cpp"
#include "../../sdl_utils/Texture.h"
#include "config/EngineConfig.h"

#include "SDL2/SDL_surface.h"

int32_t Engine::init(const EngineConfig& cfg){

    if(EXIT_SUCCESS != window_.init(cfg.windowCfg)){
        std::cerr << "window.init() failed. Reason: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    if(EXIT_SUCCESS != renderer_.init(window_.getWindow())){
        std::cerr << "Renderer.init() failed. Reason: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    if(EXIT_SUCCESS != imageContainer_.init(cfg.imageContainerConfig)){
        std::cerr << "imgContainer.init() failed. Reason: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    if(EXIT_SUCCESS != textContainer_.init(cfg.textContainerConfig)){
        std::cerr << "textContainer.init() failed. Reason: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    if(EXIT_SUCCESS != event_.init()){
        std::cerr << "InputEvent.init() failed. Reason: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    if(EXIT_SUCCESS != game_.init(cfg.gameCfg, &imageContainer_,
                                  &textContainer_)){
        std::cerr << "Game.init() failed. Reason: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void Engine::deinit(){

    game_.deinit();
    event_.deinit();
    imageContainer_.deinit();
    textContainer_.deinit();
    renderer_.deinit();
    window_.deinit();
}

void Engine::drawFrame(){
    renderer_.clearScreen();

    std::vector<DrawParams> images;
    game_.draw(images);

    SDL_Texture* texture = nullptr;

    for(const DrawParams& image : images){

        if(WidgetType::IMAGE == image.widgetType){
            texture = imageContainer_.getImageTexture(image.rsrcId);
        }
        else if(WidgetType::TEXT == image.widgetType){
            texture = textContainer_.getTextTexture(image.textId);
        }
        else {
            std::cerr << "Error, received unsupported WidgetType: " << static_cast<int32_t>(image.widgetType)
                      << " for rsrcId: " << image.rsrcId << std::endl;
            continue;
        }

        renderer_.renderTexture(texture, image);
    }

    renderer_.finishFrame();
}

void Engine::start(){
    mainLoop(); 
}

bool Engine::processFrame(){

    while(event_.pollEvent()){
        if(event_.checkForExitRequest()){
            return true;
        }

        handleEvent();        
    }

    drawFrame();

    return false;
}

void Engine::handleEvent(){
    game_.handleEvent(event_);
}

void Engine::limitFPS(const int64_t elapsedTimeMicroSeconds){
    constexpr auto maxFrames = 30;
    constexpr auto microSecondsInASecond = 1000000;
    constexpr auto microSecondsPerFrame = microSecondsInASecond / maxFrames;
    const int64_t sleepDurationMicroSeconds = microSecondsPerFrame - elapsedTimeMicroSeconds;

    if(sleepDurationMicroSeconds > 0){
        Threading::sleepFor(sleepDurationMicroSeconds);
    }
}

void Engine::mainLoop(){

    Time time;

    while(true){
        time.getElapsed();
        if(processFrame()){
            return;
        }

        limitFPS(time.getElapsed().toMicroseconds());
    }
}
