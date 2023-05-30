#ifndef UNTITLED_MONITORWINDOWCFG_H
#define UNTITLED_MONITORWINDOWCFG_H

#include <cstdint>
#include <string>

#include "../../utils/drawing/Point.h"

enum WindowFlags {
    WINDOW_SHOWN = 4,    //Equal on SDL_WINDOW_SHOWN
    //SDL_WINDOW_FULLSCREEN_DESKTOP = 4097 //SDL_WINDOW_FULLSCREEN_DESKTOP
};

struct MonitorWindowCfg {
    std::string windowName;
    Point windowPos = Point::UNDEFINED;
    int32_t windowWidth = 0;
    int32_t windowHeight = 0;
    WindowFlags windowFlags = WINDOW_SHOWN;
};

#endif //UNTITLED_MONITORWINDOWCFG_H