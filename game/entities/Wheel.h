#ifndef MANAGERS_WHEEL_H
#define MANAGERS_WHEEL_H

#include <cstdint>

#include "../../manager_utils/include/manager_utils/drawing/Image.h"

struct InputEvent;

class Wheel {
public:
    int32_t init(int32_t wheelRsrcId);
    void draw();
    void handleEvent(const InputEvent& e);
private:
    Image wheelImg_;
};


#endif //MANAGERS_WHEEL_H
