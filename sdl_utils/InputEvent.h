#ifndef SDL_UTILS_INPUTEVENT_H
#define SDL_UTILS_INPUTEVENT_H

#include "SDL2/SDL_events.h"

#include "../utils/drawing/Point.h"
#include "../utils/input/EventDefines.h"

union SDL_Event;

//Holds event position on the screen 
class InputEvent {
public:
    int32_t init();
    void deinit();
    /*Check if there is event*/
    bool pollEvent();
    bool checkForExitRequest() const;

    Point pos = Point::UNDEFINED;

    int32_t key = Keyboard::KEY_UNKNOWN;
    uint8_t mouseButton = Mouse::UNKNOWN;
    TouchEvent type = TouchEvent::UNKNOWN;

private:
    void setEventTypeInternal();

    //Holds the OS communication event system 
    SDL_Event* sdl_event_ = nullptr;
};

#endif /*SDL_UTILS_INPUTEVENT_H*/