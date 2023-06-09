#ifndef INPUT_EVENTS_GAME_H
#define INPUT_EVENTS_GAME_H

#include <cstdint>

#include "../game/config/GameCfg.h"
#include "../utils/drawing/DrawParams.h"
#include "../manager_utils/include/manager_utils/drawing/Image.h"
#include "../manager_utils/include/manager_utils/drawing/Text.h"
#include "entities/Hero.h"
#include "entities/Wheel.h"

struct InputEvent;

class Game {
public:
    int32_t init(const GameCfg& cfg);
    void deinit();
    void draw();
    void handleEvent(const InputEvent& e);
private:
    Hero hero_;
    Wheel wheel_;
    Text helloText;
    Text pressText;
    Text hideText;

};


#endif //INPUT_EVENTS_GAME_H
