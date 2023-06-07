#ifndef INPUT_EVENTS_GAME_H
#define INPUT_EVENTS_GAME_H

#include <cstdint>
#include <vector>

#include "../game/config/GameCfg.h"
#include "../utils/drawing/DrawParams.h"

struct InputEvent;


class Game {
public:
    int32_t init(const GameCfg& cfg);

    void deinit();
    void draw(std::vector<DrawParams>& outImage);
    void handleEvent(const InputEvent& e);
private:
    DrawParams pressKeysImg;
    DrawParams layer2Img;
    DrawParams helloTest;
};


#endif //INPUT_EVENTS_GAME_H
