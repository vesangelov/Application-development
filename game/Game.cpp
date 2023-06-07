#include "Game.h"

#include <iostream>

#include "../sdl_utils/InputEvent.h"
#include "../sdl_utils/containers/ImageContainer.h"
#include "../sdl_utils/containers/TextContainer.h"
#include "../utils/drawing/Color.h"
#include "../manager_utils/include/manager_utils/managers/DrawMgr.h"
#include "../manager_utils/include/manager_utils/managers/ResMgr.h"

static int32_t gFontId;

int32_t Game::init(const GameCfg& cfg){

    layer2Img.rsrcId = cfg.layer2RsrcId;
    Rectangle rect = gResMgr->getImageFrame(layer2Img.rsrcId);
    layer2Img.width = rect.w;
    layer2Img.height = rect.h;
    layer2Img.pos = Point::ZERO;
    layer2Img.widgetType = WidgetType::IMAGE;

    pressKeysImg.rsrcId = cfg.pressKeysRsrcId;
    rect = gResMgr->getImageFrame(pressKeysImg.rsrcId);
    pressKeysImg.width = rect.w;
    pressKeysImg.height = rect.h;
    pressKeysImg.pos = Point::ZERO;
    pressKeysImg.widgetType = WidgetType::IMAGE;

    gResMgr->createText("Hello C++ dudes", Colors::ORANGE, cfg.textFontId, helloTest.textId,
    helloTest.width, helloTest.height);

    helloTest.pos = Point::ZERO;
    helloTest.widgetType = WidgetType::TEXT;

    return EXIT_SUCCESS;
}

void Game::deinit(){
    gResMgr->unloadText(helloTest.textId);
}

void Game::draw(std::vector<DrawParams>& outImage){
    outImage.push_back(pressKeysImg);
    outImage.push_back(layer2Img);
    outImage.push_back(helloTest);
}

void Game::handleEvent([[maybe_unused]]const InputEvent& e){
    if(TouchEvent::KEYBOARD_RELEASE != e.type){
        return;
    }

    switch (e.key){
        case Keyboard::KEY_UP:
            pressKeysImg.pos.y -= 10;
            break;
        case Keyboard::KEY_DOWN:
            pressKeysImg.pos.y += 10;
            break;
        case Keyboard::KEY_LEFT:
            pressKeysImg.pos.x -= 10;
            break;
        case Keyboard::KEY_RIGHT:
            pressKeysImg.pos.x += 10;
            break;

        case Keyboard::KEY_Q:
            pressKeysImg.width -= 10;
            break;
        case Keyboard::KEY_W:
            pressKeysImg.width += 10;
            break;
        case Keyboard::KEY_E:
            pressKeysImg.height -= 10;
            break;
        case Keyboard::KEY_R:
            pressKeysImg.height += 10;
            break;

        case Keyboard::KEY_T:
            pressKeysImg.opacity -= 10;
            if(pressKeysImg.opacity < 0){
                pressKeysImg.opacity = 0;
            }
            break;
        case Keyboard::KEY_Y:
            pressKeysImg.opacity += 10;

            if(pressKeysImg.opacity > 255){
                pressKeysImg.opacity = 255;
            }
            break;
        case Keyboard::KEY_B:
            gResMgr->createText("Kak ste, kolegi?", Colors::GREEN, gFontId, helloTest.textId,
                                      helloTest.width, helloTest.height);
            break;

        default:
            break;
    }
}