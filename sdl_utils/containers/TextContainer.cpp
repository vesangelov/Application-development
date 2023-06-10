#include "TextContainer.h"

#include <iostream>

#include "../SDL2/SDL_ttf.h"
#include "../Texture.h"

int32_t TextContainer::init(const TextContainerConfig& cfg){

    TTF_Font* currFont = nullptr;

    for(const auto& [key , fontCfg] : cfg.fontConfigs){
        currFont = TTF_OpenFont(fontCfg.location.c_str(), fontCfg.fontSize);

        if(currFont == nullptr){
            throw std::invalid_argument("Error TTF_OpenFont for: for fontLocation: " +
            fontCfg.location + ". Reason: " + SDL_GetError());
        }

        _fonts[key] = currFont;
    }

    _textures.push_back(nullptr);
    _textures.push_back(nullptr);
    _textures.push_back(nullptr);

    return EXIT_SUCCESS;
}

void TextContainer::deinit(){
    for(auto& pair : _fonts){
        TTF_CloseFont(pair.second);
    }
}

void TextContainer::createText(const std::string& text, const Color &color, int32_t fontId,
                int32_t &outTextId, int32_t &outTextWidth,
                int32_t &outTextHeight){

    auto it = _fonts.find(fontId);

    if(it == _fonts.end()){
        throw std::invalid_argument("Font not found." + text);
    }

    TTF_Font* font = it->second;
    SDL_Texture* textTexture = nullptr;

    if(EXIT_SUCCESS != Texture::createTextureFromText(text, color, font, textTexture,
                                                      outTextWidth, outTextHeight)){
        throw std::invalid_argument("Error, createTextureFromText() failed for text: " + text);
    }

    occupyFreeSlotIndex(outTextId, textTexture);
}

void TextContainer::reloadText(const std::string& text, const Color &color, int32_t fontId,
                int32_t textId, int32_t &outTextWidth,
                int32_t &outTextHeight){

    auto it = _fonts.find(fontId);

    if(it == _fonts.end()){
        throw std::invalid_argument("Error, could not be found. Will not reload text: " + text);
        return;
    }

    freeSlotIndex(textId);

    TTF_Font* font = it->second;
    SDL_Texture* textTexture = nullptr;
    if(EXIT_SUCCESS != Texture::createTextureFromText(text, color, font, textTexture,
                                                      outTextWidth, outTextHeight)){
        throw std::invalid_argument("Error, createTextureFromText() failed for text: " + text);
    }

    _textures[textId] = textTexture;
}

void TextContainer::unloadText(int32_t textId){
    if(0 > textId || textId >= static_cast<int32_t>(_textures.size())){
        std::cout << textId;
        throw std::invalid_argument(", trying to unload non-existing textId.");
    }

    freeSlotIndex(textId);
}

SDL_Texture* TextContainer::getTextTexture(int32_t textId) const {
    if(textId < 0){
        throw std::invalid_argument("Invalid text Id");
    }

    if(0 > textId || textId >= static_cast<int32_t>(_textures.size())){
        std::cout << textId;
        throw std::invalid_argument("trying to get non-existing textId.");
    }

    return _textures[textId];
}

void TextContainer::occupyFreeSlotIndex(int32_t& outIndex, SDL_Texture* texture){
    const int32_t size = static_cast<int32_t>(_textures.size());

    for (int32_t i = 0; i < size; ++i) {
        if(_textures[i] == nullptr){
            outIndex = i;
            _textures[i] = texture;
            return;
        }
    }

    throw std::invalid_argument("No free slots.");
}

void TextContainer::freeSlotIndex(int32_t index){
    Texture::freeTexture(_textures[index]);
}