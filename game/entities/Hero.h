#ifndef MANAGERS_HERO_H
#define MANAGERS_HERO_H

#include "../../manager_utils/include/manager_utils/drawing/Image.h"

#include <cstdint>

struct InputEvent;

class Hero {
public:
    int32_t init(int32_t hersoRsrcId);
    void deinit();
    void draw();
    void handleEvent(const InputEvent& e);
private:
    Image heroImage_;
};

#endif //MANAGERS_HERO_H
