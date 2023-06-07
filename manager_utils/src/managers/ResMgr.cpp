#include "../../include/manager_utils/managers/ResMgr.h"
#include "../../include/manager_utils/cfg/ResMgrCfg.h"

#include <iostream>

ResMgr* gResMgr = nullptr;

int32_t ResMgr::init(const ResMgrCfg& cfg){
    if(EXIT_SUCCESS != ImageContainer::init(cfg.imageContainerCfg)){
        throw std::invalid_argument("imgContainer.init() failed.");
    }

    if(EXIT_SUCCESS != TextContainer::init(cfg.textContainerCfg)){
        throw std::invalid_argument("textContainer.init() failed.");
    }

    return EXIT_SUCCESS;
}

void ResMgr::deinit() {
    ImageContainer::deinit();
    TextContainer::deinit();
}

void ResMgr::process() {

}
