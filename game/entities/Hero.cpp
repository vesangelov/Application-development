#include "Hero.h"

#include "../../sdl_utils/InputEvent.h"

int32_t Hero::init(int32_t hersoRsrcId){
    heroImage_.create(hersoRsrcId, Point(0, 0));

    return EXIT_SUCCESS;
}

void Hero::deinit(){

}

void Hero::draw(){
    heroImage_.draw();
}

void Hero::handleEvent(const InputEvent& e){
    if(TouchEvent::KEYBOARD_PRESS != e.type){
        return;
    }

    switch (e.key) {
        case Keyboard::KEY_RIGHT:
            heroImage_.setFlipType(WidgetFlip::NONE);
        heroImage_.setNextFrame();
        heroImage_.moveRight(8);
            break;

        case Keyboard::KEY_LEFT:
            heroImage_.setFlipType(WidgetFlip::HORIZONTAL);
            heroImage_.setPrevFrame();
            heroImage_.moveLeft(8);
            break;

        case Keyboard::KEY_DOWN:
            heroImage_.setPrevFrame();
            heroImage_.moveDown(8);
            break;

        case Keyboard::KEY_UP:
            heroImage_.setPrevFrame();
            heroImage_.moveUp(8);
            break;

        default:
            break;
    }
}