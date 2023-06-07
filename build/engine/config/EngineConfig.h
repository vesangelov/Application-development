#ifndef INPUT_EVENTS_ENGINECONFIG_H
#define INPUT_EVENTS_ENGINECONFIG_H

#include <cstdint>

#include "../../../manager_utils/include/manager_utils/cfg/DrawMgrCfg.h"
#include "../../../manager_utils/include/manager_utils/cfg/ResMgrCfg.h"
#include "../../../sdl_utils/config/ImageContainerCfg.h"
#include "../../../game/config/GameCfg.h"
#include "../../../sdl_utils/config/TextContainerCfg.h"

struct EngineConfig {
    DrawMgrCfg drawMgrCfg;
    ResMgrCfg resMgrCfg;
    GameCfg gameCfg;
};


#endif //INPUT_EVENTS_ENGINECONFIG_H
