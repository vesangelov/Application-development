#include "Engine.h"

#include <iostream>
#include <thread>
#include <array>

#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_ttf.h>

#include "../../manager_utils/include/manager_utils/managers/DrawMgr.h"
#include "../../utils/thread/ThreadUtils.h"
#include "../../sdl_utils/time/Time.cpp"
#include "../../sdl_utils/Texture.h"
#include "config/EngineConfig.h"

#include "SDL2/SDL_surface.h"

int32_t Engine::init(const EngineConfig& cfg){

    gDrawMgr = new DrawMgr();

    if(gDrawMgr == nullptr){
        throw std::invalid_argument("DrawMgr init() failed.");
    }

    if(EXIT_SUCCESS != gDrawMgr->init(cfg.drawMgrCfg)){
        throw std::invalid_argument("gDrawMgr->init() failed.");
    }

    if(EXIT_SUCCESS != imageContainer_.init(cfg.imageContainerConfig)){
        throw std::invalid_argument("imgContainer.init() failed.");
    }

    if(EXIT_SUCCESS != textContainer_.init(cfg.textContainerConfig)){
        throw std::invalid_argument("textContainer.init() failed.");
    }

    if(EXIT_SUCCESS != event_.init()){
        throw std::invalid_argument("InputEvent.init() failed.");
    }

    if(EXIT_SUCCESS != game_.init(cfg.gameCfg, &imageContainer_,
                                  &textContainer_)){
        throw std::invalid_argument("Game.init() failed.");
    }

    return EXIT_SUCCESS;
}

void Engine::deinit(){

    game_.deinit();
    event_.deinit();
    imageContainer_.deinit();
    textContainer_.deinit();

    gDrawMgr->deinit();
    delete gDrawMgr;
    gDrawMgr = nullptr;
}

void Engine::drawFrame(){

    gDrawMgr->clearScreen();

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
            std::cout << static_cast<int32_t>(image.widgetType) << " error for rsrcIdL: " << image.rsrcId << " ";
            throw std::invalid_argument("Received unsupported WidgetType.");
        }

        gDrawMgr->addDrawCmd(image, texture);
    }

    gDrawMgr->finishFrame();
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
