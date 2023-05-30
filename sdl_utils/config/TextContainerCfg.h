#ifndef TEXT_AND_COLORS_TEXTCONTAINERCFG_H
#define TEXT_AND_COLORS_TEXTCONTAINERCFG_H

#include <cstdint>
#include <string>
#include <unordered_map>

struct FontCfg {
    std::string location;
    int32_t fontSize= 0;
};

struct TextContainerConfig {
    std::unordered_map<int32_t, FontCfg> fontConfigs;
};

#endif //TEXT_AND_COLORS_TEXTCONTAINERCFG_H
