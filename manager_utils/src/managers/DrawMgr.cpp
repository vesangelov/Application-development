#include "../../include/manager_utils/managers/DrawMgr.h"
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


void DrawMgr::addDrawCmd(const DrawParams &drawParams, SDL_Texture* texture) {
    renderer_.renderTexture(texture, drawParams);
}
