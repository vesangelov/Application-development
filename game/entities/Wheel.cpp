#include "Wheel.h"

#include "../../sdl_utils/InputEvent.h"

int32_t Wheel::init(int32_t wheelRsrcId){
    wheelImg_.create(wheelRsrcId);

    return EXIT_SUCCESS;
}

void Wheel::draw(){
    wheelImg_.draw();
}

void Wheel::handleEvent(const InputEvent& e){

    if(TouchEvent::KEYBOARD_PRESS != e.type){
        return;
    }

    switch (e.key) {
        case Keyboard::KEY_P:
            wheelImg_.rotateRight(20);
            break;

        case Keyboard::KEY_O:
            wheelImg_.rotateLeft(20);
            break;

        case Keyboard::KEY_K:
            wheelImg_.setRotationCenter(Point::ZERO);
            break;

        case Keyboard::KEY_L:
        {
            Point rotCenter(wheelImg_.getWidth(), wheelImg_.getHeight());
            rotCenter.x /= 2;
            rotCenter.y /= 2;
            wheelImg_.setRotationCenter(rotCenter);
        }
            break;

        default:
            break;
    }
}