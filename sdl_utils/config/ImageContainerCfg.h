#ifndef HARDWARE_ACCELERATION_IMAGECONTAINERCFG_H
#define HARDWARE_ACCELERATION_IMAGECONTAINERCFG_H

#include <cstdint>
#include <string>
#include <unordered_map>

struct ImageCfg {
    std::string location;
    int32_t width = 0;
    int32_t height = 0;
};

struct ImageContainerConfig {
    std::unordered_map<int32_t, ImageCfg> imageConfigs;
};

#endif //HARDWARE_ACCELERATION_IMAGECONTAINERCFG_H
