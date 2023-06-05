#ifndef TEXT_AND_COLORS_DRAWMGRCFG_H
#define TEXT_AND_COLORS_DRAWMGRCFG_H

#include <cstdint>

#include "../../../../sdl_utils/config/MonitorWindowCfg.h"

struct DrawMgrCfg {
    MonitorWindowCfg windowCfg;
    int64_t maxFrameRate = 0;
};

#endif //TEXT_AND_COLORS_DRAWMGRCFG_H
