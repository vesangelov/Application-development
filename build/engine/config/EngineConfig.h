#ifndef INPUT_EVENTS_ENGINECONFIG_H
#define INPUT_EVENTS_ENGINECONFIG_H

#include <cstdint>

#include "../../../sdl_utils/config/MonitorWindowCfg.h"
#include "../../../sdl_utils/config/ImageContainerCfg.h"
#include "../../../game/config/GameCfg.h"
#include "../../../sdl_utils/config/TextContainerCfg.h"

struct EngineConfig {
    MonitorWindowCfg windowCfg;
    ImageContainerConfig imageContainerConfig;
    GameCfg gameCfg;
    TextContainerConfig textContainerConfig;
};


#endif //INPUT_EVENTS_ENGINECONFIG_H
