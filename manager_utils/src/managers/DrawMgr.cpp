#include "../../include/manager_utils/managers/DrawMgr.h"
#include "../../include/manager_utils/managers/ResMgr.h"
#include "../../include/manager_utils/cfg/DrawMgrCfg.h"

#include <iostream>

DrawMgr *gDrawMgr = nullptr;

int32_t DrawMgr::init(const DrawMgrCfg& cfg){

    if(EXIT_SUCCESS != window_.init(cfg.windowCfg)){
        throw std::invalid_argument("window.init() failed.");
    }

    if(EXIT_SUCCESS != renderer_.init(window_.getWindow())){
        throw std::invalid_argument("Renderer.init() failed.");
    }

    return EXIT_SUCCESS;
}

void DrawMgr::deinit() {
    renderer_.deinit();
    window_.deinit();
}

void DrawMgr::process() {

}

void DrawMgr::clearScreen() {
    renderer_.clearScreen();
}

void DrawMgr::finishFrame() {
    renderer_.finishFrame();
}


void DrawMgr::addDrawCmd(const DrawParams &drawParams) {
    SDL_Texture* texture = getTextureInternal(drawParams);
    renderer_.renderTexture(texture, drawParams);
}

SDL_Texture* DrawMgr::getTextureInternal(const DrawParams &drawParams) const {

    if(WidgetType::IMAGE == drawParams.widgetType){
        return gResMgr->getImageTexture(drawParams.rsrcId);
    }
    else if(WidgetType::TEXT == drawParams.widgetType){
        return gResMgr->getTextTexture(drawParams.textId);
    }
    else {
        std::cout << static_cast<int32_t>(drawParams.widgetType) << " error for rsrcIdL: " << drawParams.rsrcId << " ";
        throw std::invalid_argument("Received unsupported WidgetType.");
    }

    return nullptr;
}

void DrawMgr::setWidgetBlendMode(const DrawParams &drawParams, BlendMode blendMode) {
    SDL_Texture* texture = getTextureInternal(drawParams);
    renderer_.setWidgetBlendMode(texture, blendMode);
}
void DrawMgr::setWidgetOpacity(const DrawParams &drawParams, int32_t opacity){

    if(drawParams.widgetType == WidgetType::IMAGE){
        return;
    }

    SDL_Texture* texture = getTextureInternal(drawParams);
    renderer_.setWidgetOpacity(texture, opacity);
}
