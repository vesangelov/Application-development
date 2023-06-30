#include "Engine.h"

#include <iostream>
#include <thread>
#include <array>

#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_ttf.h>

#include "../../manager_utils/include/manager_utils/managers/DrawMgr.h"
#include "../../manager_utils/include/manager_utils/managers/ResMgr.h"
#include "../../utils/thread/ThreadUtils.h"
#include "../../sdl_utils/time/Time.cpp"
#include "config/EngineConfig.h"


int32_t Engine::init(const EngineConfig& cfg){

    if(EXIT_SUCCESS != mgrHandler_.init(cfg.mgrHandlerCfg)){
        throw std::invalid_argument("InputEvent.init() failed.");
    }

    if(EXIT_SUCCESS != event_.init()){
        throw std::invalid_argument("InputEvent.init() failed.");
    }

    if(EXIT_SUCCESS != game_.init(cfg.gameCfg)){
        throw std::invalid_argument("Game.init() failed.");
    }

    return EXIT_SUCCESS;
}

void Engine::deinit(){

    game_.deinit();
    mgrHandler_.deinit();
    event_.deinit();
}

void Engine::drawFrame(){

    gDrawMgr->clearScreen();

    game_.draw();

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
