#ifndef INPUT_EVENTS_RENDERER_H
#define INPUT_EVENTS_RENDERER_H

#include <cstdint>
#include <vector>

#include "../utils/drawing/DrawParams.h"

struct SDL_Renderer;
struct SDL_Texture;
struct SDL_Window;

class Renderer {
public:
    Renderer() = default;

    Renderer(const Renderer& other) = delete;
    Renderer(Renderer&& other) = delete;

    Renderer& operator=(const Renderer& other) = delete;
    Renderer& operator=(Renderer&& other) = delete;

    int32_t init(SDL_Window* window);
    void deinit();
    void clearScreen();
    void finishFrame();
    void renderTexture(SDL_Texture* texture, const DrawParams& drawParams);
    void setWidgetBlendMode(SDL_Texture* texture, BlendMode blendMode);
    void setWidgetOpacity(SDL_Texture* texture, int32_t opacity);
private:
    void drawImage(const DrawParams& drawParams, SDL_Texture *texture);
    void drawText(const DrawParams& drawParams, SDL_Texture *texture);

    SDL_Renderer * sdlRenderer_ = nullptr;
};


#endif //INPUT_EVENTS_RENDERER_H
