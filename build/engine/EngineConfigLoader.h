#ifndef INPUT_EVENTS_ENGINECONFIGLOADER_H
#define INPUT_EVENTS_ENGINECONFIGLOADER_H

#include "config/EngineConfig.h"

class EngineConfigLoader {
public:
    EngineConfigLoader() = delete;
    ~EngineConfigLoader() = default;

    static EngineConfig loadConfig();
};

#endif //INPUT_EVENTS_ENGINECONFIGLOADER_H
