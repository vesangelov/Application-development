#include "Game.h"

#include <iostream>

#include "../sdl_utils/InputEvent.h"
#include "../sdl_utils/containers/ImageContainer.h"
#include "../sdl_utils/containers/TextContainer.h"
#include "../utils/drawing/Color.h"

int32_t Game::init(const GameCfg& cfg){

    //layer2Img.create(cfg.layer2RsrcId);
    pressKeysImg.create(cfg.pressKeysRsrcId);
    helloText.create("Hello, C++ dudes.", cfg.textFontId, Colors::GREEN);
    pressText.create("Press text M", cfg.textFontId, Colors::BLUE);
    hideText.create("Hide text N", cfg.textFontId, Colors::RED);

    return EXIT_SUCCESS;
}

void Game::deinit(){
    helloText.destroy();
}

void Game::draw(){

    pressKeysImg.draw();
    pressText.draw();
    hideText.draw();
}

void Game::handleEvent([[maybe_unused]]const InputEvent& e){
    if(TouchEvent::KEYBOARD_RELEASE != e.type){
        return;
    }

    switch (e.key){
        case Keyboard::KEY_UP:
            pressKeysImg.moveUp(10);
            break;
        case Keyboard::KEY_DOWN:
            pressKeysImg.moveDown(10);
            break;
        case Keyboard::KEY_LEFT:
            pressKeysImg.moveLeft(10);
            break;
        case Keyboard::KEY_RIGHT:
            pressKeysImg.moveRight(10);
            break;

        case Keyboard::KEY_Q:
            pressKeysImg.setWidth(pressKeysImg.getWidth() - 10);
            break;
        case Keyboard::KEY_W:
            pressKeysImg.setWidth(pressKeysImg.getWidth() + 10);
            break;
        case Keyboard::KEY_E:
            pressKeysImg.setHeight(pressKeysImg.getHeight() - 10);
            break;
        case Keyboard::KEY_R:
            pressKeysImg.setHeight(pressKeysImg.getHeight() + 10);
            break;

        case Keyboard::KEY_T:
            pressKeysImg.setOpacity(pressKeysImg.getOpacity() - 10);
            if(pressKeysImg.getOpacity() < 0){
                pressKeysImg.setOpacity(0);
            }
            break;
        case Keyboard::KEY_Y:
            pressKeysImg.setOpacity(pressKeysImg.getOpacity() + 10);

            if(pressKeysImg.getOpacity() > 255){
                pressKeysImg.setOpacity(255);
            }
            break;
        case Keyboard::KEY_B:
            helloText.setText("Kak ste kolegi?");
            break;
        case Keyboard::KEY_M:
            hideText.show();
            pressText.hide();
            break;
        case Keyboard::KEY_N:
            hideText.hide();
            pressText.show();
            break;

        default:
            break;
    }
}