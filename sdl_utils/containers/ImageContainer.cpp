#include "ImageContainer.h"

#include <iostream>

#include "../Texture.h"
#include "../../utils/drawing/DrawParams.h"

int32_t ImageContainer::init(const ImageContainerConfig& cfg){

    for(const auto& [resId, element] : cfg.imageConfigs){

        if(EXIT_SUCCESS != loadSingleResource(element, resId)) {
            std::cerr << "createSurfaceFromFile: " << element.location << std::endl;
            return EXIT_FAILURE;
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

        return nullptr;
    }

    return it->second;
}

Rectangle ImageContainer::getImageFrame(int32_t rsrcId) const{
    auto it = _textureFrames.find(rsrcId);

    if(it == _textureFrames.end()){
        std::cerr << "Error, invalid rsrcId: " << rsrcId << " requested."
                                                            "Returning Zero rectangle" << std::endl;

        return Rectangle::ZERO;
    }

    return it->second;
}

int32_t ImageContainer::loadSingleResource(const ImageCfg& resources, [[maybe_unused]]int32_t rsrcId){
    SDL_Texture* texture = nullptr;

    if(EXIT_SUCCESS != Texture::createTextureFromFile(resources.location, texture)) {
        std::cerr << "createSurfaceFromFile: " << resources.location << std::endl;
        return EXIT_FAILURE;
    }

    //TODO remove me
    //temporary enable alpha blending for all existing textures
    if(EXIT_SUCCESS != Texture::setBlendModeTexture(texture, BlendMode::BLEND)) {
        throw std::runtime_error("Unable to set blend mode.");
        std::cerr << "setBlendModeTexture() failed for file: " << resources.location << std::endl;
        return EXIT_FAILURE;
    }

    textures_[rsrcId] = texture;

    Rectangle& rect = _textureFrames[rsrcId];
    rect.x = 0;
    rect.y = 0;
    rect.w = resources.width;
    rect.h = resources.height;

    return EXIT_SUCCESS;
}