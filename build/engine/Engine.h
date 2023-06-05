#ifndef ENGINE_ENGINE_H_
#define ENGINE_ENGINE_H_

#include <cstdint>

#include "../../sdl_utils/InputEvent.h"
#include "../../game/Game.h"
#include "../../sdl_utils/containers/ImageContainer.h"
#include "../../sdl_utils/containers/TextContainer.h"

struct SDL_Surface;
struct EngineConfig;

class Engine {
public:
    int32_t init(const EngineConfig& cfg);
    void deinit();
    void start();

private:
    void mainLoop();
    void drawFrame();
    bool processFrame();
    void handleEvent();

    void limitFPS(const int64_t elapsedTimeMicroSeconds);

    InputEvent event_;
    ImageContainer imageContainer_;
    Game game_;
    TextContainer textContainer_;
};

#endif /*_ENGINE_ENGINE_H_*/
