#ifndef INPUT_EVENTS_ENGINECONFIG_H
#define INPUT_EVENTS_ENGINECONFIG_H

#include <cstdint>

#include "../../../manager_utils/include/manager_utils/cfg/DrawMgrCfg.h"
#include "../../../sdl_utils/config/ImageContainerCfg.h"
#include "../../../game/config/GameCfg.h"
#include "../../../sdl_utils/config/TextContainerCfg.h"

struct EngineConfig {
    DrawMgrCfg drawMgrCfg;
    ImageContainerConfig imageContainerConfig;
    GameCfg gameCfg;
    TextContainerConfig textContainerConfig;
};


#endif //INPUT_EVENTS_ENGINECONFIG_H
