#ifndef TEXT_AND_COLORS_RESMGR_H
#define TEXT_AND_COLORS_RESMGR_H

#include "MgrBase.h"

#include "../../../../sdl_utils/containers/ImageContainer.h"
#include "../../../../sdl_utils/containers/TextContainer.h"

struct ResMgrCfg;

class ResMgr : public MgrBase,
               public ImageContainer,
               public TextContainer {
public:
    ResMgr() = default;

    ResMgr(const ResMgr& other) = delete;
    ResMgr(ResMgr&& other) = delete;

    ResMgr& operator=(const ResMgr& other) = delete;
    ResMgr& operator=(ResMgr&& other) = delete;

    int32_t init(const ResMgrCfg& cfg);

    void deinit() final;
    void process() final;
};

extern ResMgr* gResMgr;

#endif //TEXT_AND_COLORS_RESMGR_H
