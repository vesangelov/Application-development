#ifndef TEXT_AND_COLORS_DRAWMGR_H
#define TEXT_AND_COLORS_DRAWMGR_H

#include "MgrBase.h"

#include "../../../../sdl_utils/Renderer.h"
#include "../../../../sdl_utils/MonitorWindow.h"

struct DrawMgrCfg;
struct SDL_Texture;

class DrawMgr : public MgrBase {
public:

    DrawMgr() = default;

    DrawMgr(const DrawMgr& other) = delete;
    DrawMgr(DrawMgr&& other) = delete;

    DrawMgr& operator=(const DrawMgr& other) = delete;
    DrawMgr& operator=(DrawMgr&& other) = delete;

    int32_t init(const DrawMgrCfg& cfg);

    void deinit() final;
    void process() final;

    void clearScreen();

    void finishFrame();

    void addDrawCmd(const DrawParams &drawParams, SDL_Texture* texture);

private:
    Renderer renderer_;

    MonitorWindow window_;

    //Hold maximum frame rate cap
    uint32_t _maxFrames { 0 };
};

extern DrawMgr *gDrawMgr;


#endif //TEXT_AND_COLORS_DRAWMGR_H
