#ifndef INPUT_EVENTS_ENGINECONFIG_H
#define INPUT_EVENTS_ENGINECONFIG_H

#include <cstdint>

#include "../../../sdl_utils/config/ImageContainerCfg.h"
#include "../../../game/config/GameCfg.h"
#include "../../../sdl_utils/config/TextContainerCfg.h"
#include "../../../manager_utils/include/manager_utils/cfg/MgrHandlerCfg.h"

struct EngineConfig {
    MgrHandlerCfg mgrHandlerCfg;
    GameCfg gameCfg;
};


#endif //INPUT_EVENTS_ENGINECONFIG_H
