#ifndef UNTITLED_MONITORWINDOW_H
#define UNTITLED_MONITORWINDOW_H

#include <cstdint>
#include <string>

#include "../utils/drawing/Point.h"
#include "../utils/drawing/Rectangle.h"
#include "config/MonitorWindowCfg.h"

//Forward declaration
struct SDL_Window;
struct SDL_Surface;

class MonitorWindow {
public:
    MonitorWindow() = default;
    ~MonitorWindow();

    MonitorWindow(const MonitorWindow& other) = delete;
    MonitorWindow(MonitorWindow&& other) = delete;

    MonitorWindow operator=(const MonitorWindow& other) = delete;
    MonitorWindow operator=(MonitorWindow&& other) = delete;

    int32_t init(const MonitorWindowCfg& cfg);

    void deinit();

    void updateWindowSurface();

    SDL_Window* getWindow();

private:
SDL_Window* window_;
Rectangle windowRect_ = Rectangle::UNDEFINED;
};

#endif //UNTITLED_MONITORWINDOW_H