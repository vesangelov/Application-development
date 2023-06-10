#include "../../../manager_utils/include/manager_utils/managers/MgrHandler.h"
#include "../../../manager_utils/include/manager_utils/managers/ResMgr.h"
#include "../../../manager_utils/include/manager_utils/managers/DrawMgr.h"
#include "../../../manager_utils/include/manager_utils/cfg/MgrHandlerCfg.h"

#include <iostream>

int32_t MgrHandler::init(const MgrHandlerCfg& cfg){
    gDrawMgr = new DrawMgr();

    if(gDrawMgr == nullptr){
        throw std::invalid_argument("DrawMgr init() failed.");
    }

    if(EXIT_SUCCESS != gDrawMgr->init(cfg.drawMgrCfg)){
        throw std::invalid_argument("gDrawMgr->init() failed.");
    }

    gResMgr = new ResMgr();

    if(gResMgr == nullptr){
        throw std::invalid_argument("DrawMgr init() failed.");
    }

    if(EXIT_SUCCESS != gResMgr->init(cfg.resMgrCfg)){
        throw std::invalid_argument("gDrawMgr->init() failed.");
    }

    managers_[DRAW_MGR_IDX] = static_cast<MgrBase*>(gDrawMgr);
    managers_[RSRC_MGR_IDX] = static_cast<MgrBase*>(gResMgr);

    return EXIT_SUCCESS;
}

void MgrHandler::deinit(){
    gResMgr->deinit();
    delete gResMgr;
    gResMgr = nullptr;

    gDrawMgr->deinit();
    delete gDrawMgr;
    gDrawMgr = nullptr;

    for (int32_t i = MANAGERS_COUNT - 1; i >= 0; --i) {
        managers_[i]->deinit();
        delete managers_[i];
        managers_[i] = nullptr;
    }
}

void MgrHandler::process(){
    for (int32_t i = 0; i < MANAGERS_COUNT; ++i) {
        managers_[i]->process();
    }
}

void MgrHandler::nuliftGlobalMgr(int32_t mgrIdx){
    switch (mgrIdx) {
        case DRAW_MGR_IDX:
            delete gDrawMgr;
            gDrawMgr = nullptr;
            break;
        case RSRC_MGR_IDX:
            delete gResMgr;
            gResMgr = nullptr;
            break;
        default:
            std::cerr << "Received invalid mgrIdx: " << mgrIdx << std::endl;
            break;
    }
}