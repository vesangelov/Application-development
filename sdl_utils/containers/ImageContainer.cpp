#include "ImageContainer.h"

#include <iostream>

#include "../Texture.h"
#include "../../utils/drawing/DrawParams.h"

static const Frames EMPTY_FRAMES { Rectangle::ZERO };

int32_t ImageContainer::init(const ImageContainerConfig& cfg){

    for(const auto& [resId, element] : cfg.imageConfigs){

        if(EXIT_SUCCESS != loadSingleResource(element, resId)) {
            throw std::invalid_argument("createSurfaceFromFile: " + element.location);
        }
    }

    return EXIT_SUCCESS;
}

void ImageContainer::deinit(){

    for (auto& [resId, element] : textures_) {
        Texture::freeTexture(element);
    }
}

SDL_Texture* ImageContainer::getImageTexture(int32_t rsrcId) const{
    auto it = textures_.find(rsrcId);

    if(it == textures_.end()){
        std::cerr << "Error, invalid rsrcId: " << rsrcId << " requested" << std::endl;

        throw std::runtime_error("Not found.");
    }

    return it->second;
}

const Frames& ImageContainer::getImageFrame(int32_t rsrcId) const{
    auto it = _textureFrames.find(rsrcId);

    if(it == _textureFrames.end()){
        std::cerr << "Error, invalid rsrcId: " << rsrcId << " requested."
                                                            "Returning Zero rectangle" << std::endl;

        return EMPTY_FRAMES;
    }

    return it->second;
}

int32_t ImageContainer::loadSingleResource(const ImageCfg& resources, [[maybe_unused]]int32_t rsrcId){
    SDL_Texture* texture = nullptr;

    if(EXIT_SUCCESS != Texture::createTextureFromFile(resources.location, texture)) {
        throw std::invalid_argument("createSurfaceFromFile: " + resources.location);
    }

    //TODO remove me
    //temporary enable alpha blending for all existing textures
    if(EXIT_SUCCESS != Texture::setBlendModeTexture(texture, BlendMode::BLEND)) {
        throw std::runtime_error("Unable to set blend mode.");
    }

    textures_[rsrcId] = texture;
    _textureFrames[rsrcId] = resources.frames;

    return EXIT_SUCCESS;
}