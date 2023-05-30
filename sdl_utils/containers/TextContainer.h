#ifndef TEXT_AND_COLORS_TEXTCONTAINER_H
#define TEXT_AND_COLORS_TEXTCONTAINER_H

#include <cstdint>
#include <vector>
#include <unordered_map>

#include "../config/TextContainerCfg.h"

struct SDL_Texture;
typedef struct _TTF_Font TTF_Font;
struct Color;

class TextContainer {
public:
    int32_t init(const TextContainerConfig& cfg);

    void deinit();

    void createText(const std::string& text, const Color &color, int32_t fontId,
                    int32_t &outTextId, int32_t &outTextWidth,
                    int32_t &outTextHeight);

    void reloadText(const std::string& text, const Color &color, int32_t fontId,
                    int32_t textId, int32_t &outTextWidth,
                    int32_t &outTextHeight);

    void unloadText(int32_t textId);

    SDL_Texture* getTextTexture(int32_t textId) const;


private:
    void occupyFreeSlotIndex(int32_t& outIndex, SDL_Texture* texture);
    void freeSlotIndex(int32_t index);
    //the textures we'll be drawing
    std::vector<SDL_Texture*> _textures;

    std::unordered_map<int32_t, TTF_Font*> _fonts;
};


#endif //TEXT_AND_COLORS_TEXTCONTAINER_H
