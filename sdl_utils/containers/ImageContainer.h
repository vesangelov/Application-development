#ifndef HARDWARE_ACCELERATION_IMAGECONTAINER_H
#define HARDWARE_ACCELERATION_IMAGECONTAINER_H

#include <cstdint>
#include <unordered_map>

#include "../config/ImageContainerCfg.h"
#include "../../sdl_utils/MonitorWindow.h"
#include "../../utils/drawing/DrawParams.h"

struct SDL_Texture;

class ImageContainer {
public:
    int32_t init(const ImageContainerConfig& cfg);

    void deinit();

    SDL_Texture* getImageTexture(int32_t rsrcId) const;

    Rectangle getImageFrame(int32_t rsrcId) const;
private:
    int32_t loadSingleResource(const ImageCfg& resCfg, int32_t rsrcId);
    //the textures we'll be drawing
    std::unordered_map<int32_t, SDL_Texture*> textures_;

    std::unordered_map<int32_t, Rectangle> _textureFrames;

    int setBlendModeTexture(SDL_Texture *pTexture, BlendMode mode);
};


#endif //HARDWARE_ACCELERATION_IMAGECONTAINER_H
