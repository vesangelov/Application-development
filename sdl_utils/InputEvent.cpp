#include "InputEvent.h"

#include <iostream>

#include <SDL2/SDL_events.h>

int32_t InputEvent::init(){

    sdl_event_ = new SDL_Event{};

    if(sdl_event_ == nullptr){
        std::invalid_argument("Bad alloc for SDL_EVENT()");
    }

    return EXIT_SUCCESS;
}

void InputEvent::deinit(){

    if(sdl_event_ != nullptr){
        delete sdl_event_;
        sdl_event_ = nullptr;
    }
}

bool InputEvent::pollEvent(){

    if(0 == SDL_PollEvent(sdl_event_)){
        //no events
        return false;
    }

    SDL_GetMouseState(&pos.x, &pos.y);
    setEventTypeInternal();

    return true;
}

void InputEvent::setEventTypeInternal() {
  switch (sdl_event_->type) {
  case EventType::KEYBOARD_PRESS:
    key = sdl_event_->key.keysym.sym;
    mouseButton = Mouse::UNKNOWN;
    type = TouchEvent::KEYBOARD_PRESS;
    break;

  case EventType::KEYBOARD_RELEASE:
    key = sdl_event_->key.keysym.sym;
    mouseButton = Mouse::UNKNOWN;
    type = TouchEvent::KEYBOARD_RELEASE;
    break;
    
    //NOTE: the fall-through is intentional
  case EventType::MOUSE_PRESS:
    key = Keyboard::KEY_UNKNOWN;
    mouseButton = sdl_event_->button.button;
    type = TouchEvent::TOUCH_PRESS;
    break;

  case EventType::FINGER_PRESS:
    key = Keyboard::KEY_UNKNOWN;
    mouseButton = Mouse::UNKNOWN;
    type = TouchEvent::TOUCH_PRESS;
    break;

  case EventType::MOUSE_RELEASE:
    key = Keyboard::KEY_UNKNOWN;
    mouseButton = sdl_event_->button.button;
    type = TouchEvent::TOUCH_RELEASE;
    break;

  case EventType::FINGER_RELEASE:
    key = Keyboard::KEY_UNKNOWN;
    mouseButton = Mouse::UNKNOWN;
    type = TouchEvent::TOUCH_PRESS;
    break;

    //X is pressed on the window (or CTRL-C signal is sent)
  case EventType::QUIT:
    key = Keyboard::KEY_UNKNOWN;
    mouseButton = Mouse::UNKNOWN;
    type = TouchEvent::UNKNOWN;
    break;

  default:
    key = Keyboard::KEY_UNKNOWN;
    mouseButton = Mouse::UNKNOWN;
    type = TouchEvent::UNKNOWN;
    break;
  }
}

bool InputEvent::checkForExitRequest() const{

    return (sdl_event_->type == EventType::QUIT)
    || (type == TouchEvent::KEYBOARD_PRESS && Keyboard::KEY_ESCAPE == key);
}