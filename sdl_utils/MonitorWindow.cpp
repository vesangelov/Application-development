#include "MonitorWindow.h"
#include "config/MonitorWindowCfg.h"

#include <iostream>

#include <SDL2/SDL_video.h>

int32_t MonitorWindow::init(const MonitorWindowCfg& cfg){

    Point finalPos;

    if(cfg.windowPos == Point::UNDEFINED){
        finalPos.x = SDL_WINDOWPOS_UNDEFINED;
        finalPos.y = SDL_WINDOWPOS_UNDEFINED;
    }
    else {
        finalPos = cfg.windowPos;
    }

    window_ = SDL_CreateWindow(cfg.windowName.c_str(), finalPos.x, 
    finalPos.y, cfg.windowWidth, cfg.windowHeight, cfg.windowFlags);

    if(window_ == nullptr){
        std::cerr << "SDL_CreateWindow failed. Reason: " << SDL_GetError() << std::endl;
    }

    return EXIT_SUCCESS;
}

void MonitorWindow::deinit(){

    if(window_ != nullptr){
        SDL_DestroyWindow(window_);
        window_ = nullptr;
    }
}

void MonitorWindow::updateWindowSurface(){

    if(EXIT_SUCCESS != SDL_UpdateWindowSurface(window_)){
        std::cerr << "SDL_UpdateWindowSurface() failed. Reason: " << SDL_GetError() << std::endl;
        return;
    }
}

MonitorWindow::~MonitorWindow(){
    deinit();
}

SDL_Window* MonitorWindow::getWindow(){
    return window_;
}