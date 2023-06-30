#include "Game.h"

#include <iostream>

#include "../sdl_utils/InputEvent.h"
#include "../sdl_utils/containers/ImageContainer.h"
#include "../sdl_utils/containers/TextContainer.h"
#include "../utils/drawing/Color.h"

int32_t Game::init(const GameCfg& cfg){

    if(EXIT_SUCCESS != hero_.init(cfg.runningGirlRsrcId)){
        throw std::invalid_argument("hero.init failed()");
    }

    if(EXIT_SUCCESS != wheel_.init(cfg.wheelRsrcId)){
        throw std::invalid_argument("wheel.init failed()");
    }

    return EXIT_SUCCESS;
}

void Game::deinit(){
    hero_.deinit();
}

void Game::draw(){
    wheel_.draw();
    hero_.draw();
}

void Game::handleEvent([[maybe_unused]]const InputEvent& e){

    hero_.handleEvent(e);
    wheel_.handleEvent(e);

    if(TouchEvent::KEYBOARD_RELEASE != e.type){
        return;
    }
}