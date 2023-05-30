#ifndef INPUT_EVENTS_GAME_H
#define INPUT_EVENTS_GAME_H

#include <cstdint>
#include <vector>

#include "../game/config/GameCfg.h"
#include "../utils/drawing/DrawParams.h"

struct InputEvent;
struct ImageContainer;
struct TextContainer;

class Game {
public:
    int32_t init(const GameCfg& cfg, const ImageContainer* imageContainerInterface,
                 TextContainer* textContainerInterface);
    void deinit();
    void draw(std::vector<DrawParams>& outImage);
    void handleEvent(const InputEvent& e);
private:
    DrawParams pressKeysImg;
    DrawParams layer2Img;
    DrawParams helloTest;

    //TODO remove me!
    const ImageContainer* imageContainer_ = nullptr;
    TextContainer* textContainer = nullptr;
};


#endif //INPUT_EVENTS_GAME_H
