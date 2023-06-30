#ifndef HARDWARE_ACCELERATION_IMAGECONTAINERCFG_H
#define HARDWARE_ACCELERATION_IMAGECONTAINERCFG_H

#include <cstdint>
#include <string>
#include <unordered_map>
#include <vector>

struct Rectangle;

struct ImageCfg {
    std::string location;
    std::vector<Rectangle> frames;
};

struct ImageContainerConfig {
    std::unordered_map<int32_t, ImageCfg> imageConfigs;
};

#endif //HARDWARE_ACCELERATION_IMAGECONTAINERCFG_H
