#include "Renderer.h"

#include <iostream>

#include "SDL2/SDL_render.h"
#include "SDL2/SDL_hints.h"
#include "Texture.h"

int32_t Renderer::init(SDL_Window* window){

    if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")){
    std::cerr << "Warning: Linear texture filtering not enabled! "
                 "SDL_SetHint() failed. SDL Error: " << SDL_GetError()<< std::endl;
    return EXIT_FAILURE;
    }
    constexpr auto unspecifiedDriveId = -1;

    sdlRenderer_ = SDL_CreateRenderer(window, unspecifiedDriveId, SDL_RENDERER_ACCELERATED);
    if(sdlRenderer_ == nullptr){
        std::cerr << "SDL_CreateRenderer() failed. Reason: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    if(EXIT_SUCCESS != SDL_SetRenderDrawColor(sdlRenderer_, 0, 0, 255, SDL_ALPHA_OPAQUE)){
        std::cerr << "SDL_SetRenderDrawColor() failed. Reason: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    Texture::setRenderer(sdlRenderer_);

    return EXIT_SUCCESS;
}

void Renderer::deinit(){
    if(sdlRenderer_ != nullptr){
        SDL_DestroyRenderer(sdlRenderer_);
        sdlRenderer_ = nullptr;
    }
}

void Renderer::clearScreen(){

    if(EXIT_SUCCESS != SDL_RenderClear(sdlRenderer_)){
        std::cerr << "SDL_RenderClear()() failed. Reason: " << SDL_GetError() << std::endl;
    }
}

void Renderer::finishFrame(){
    SDL_RenderPresent(sdlRenderer_);
}

void Renderer::renderTexture(SDL_Texture* texture, const DrawParams& drawParams){

    if(WidgetType::IMAGE == drawParams.widgetType){
        drawImage(drawParams, texture);
    }
    else if(WidgetType::TEXT == drawParams.widgetType){
        drawText(drawParams, texture);
    }
    else {
        std::cerr << "Error, received unsupported WidgetType: " << static_cast<int32_t>(drawParams.widgetType)
        << " for rsrcId: " << drawParams.rsrcId << std::endl;
    }
}

void Renderer::drawImage(const DrawParams& drawParams, SDL_Texture *texture){

    if(FULL_OPACITY == drawParams.opacity){
        drawTextureInternal(drawParams, texture);
    }
    else {
        if(EXIT_SUCCESS != Texture::setAlphaTexture(texture, drawParams.opacity)){
            std::cerr << "Texture::setAlphaTexture() failed for resource Id: " << drawParams.rsrcId << std::endl;
        }
    }

    drawTextureInternal(drawParams, texture);

    if(EXIT_SUCCESS != Texture::setAlphaTexture(texture, drawParams.opacity)){
        std::cerr << "Texture::setAlphaTexture() failed for resource Id: " << drawParams.rsrcId << std::endl;
    }
}

void Renderer::drawTextureInternal(const DrawParams& drawParams, SDL_Texture *texture){
    const SDL_Rect destRec = { .x = drawParams.pos.x, .y = drawParams.pos.y,
            .w = drawParams.width, .h = drawParams.height};

    const SDL_Rect* sourceRect = reinterpret_cast<const SDL_Rect*>(&drawParams.frameRect);

    const SDL_Point* center = reinterpret_cast<const SDL_Point*>(&drawParams.rotationCenter);

    const int32_t error =  SDL_RenderCopyEx(sdlRenderer_, texture, sourceRect, &destRec,
                                            drawParams.rotationAngle, center,
                                            static_cast<SDL_RendererFlip>(drawParams.flipType));

    if(EXIT_SUCCESS != error){
        std::cerr << "SDL_RenderCopy(() failed for resource Id: "
                  << drawParams.rsrcId << "Reason: " << SDL_GetError() << std::endl;
    }
}

void Renderer::drawText(const DrawParams& drawParams, SDL_Texture *texture){
    drawTextureInternal(drawParams, texture);
}

void Renderer::setWidgetBlendMode(SDL_Texture* texture, BlendMode blendMode){
    if(EXIT_SUCCESS != Texture::setBlendModeTexture(texture, blendMode)){
        throw std::invalid_argument("setBlendModeTexture failed");
    }
}

void Renderer::setWidgetOpacity(SDL_Texture* texture, int32_t opacity){
    if(EXIT_SUCCESS != Texture::setAlphaTexture(texture, opacity)){
        throw std::invalid_argument("setAlphaTexture failed");
    }
}
