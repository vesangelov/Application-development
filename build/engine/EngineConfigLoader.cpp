#include "EngineConfigLoader.h"
#include "../../common/CommonDefines.h"

namespace {
    constexpr auto WINDOW_WIDTH = 1024;
    constexpr auto WINDOW_HEIGTH = 800;
    constexpr auto WINDOW_NAME = "Scale and alpha blending";

    constexpr auto RUNNING_GIRL_FRAMES = 6;
    constexpr auto RUNNING_GIRL_KEYS_WIDTH = 256;
    constexpr auto RUNNING_GIRL_KEYS_HEIGHT = 220;

    constexpr auto WHEEL_IMG_WIDTH = 695;
    constexpr auto WHEEL_IMG_HEIGHT = 695;

    constexpr auto ANGELINE_VINTAGE_40_FONT_SIZE = 40;

    constexpr auto MAX_FRAMERATE = 30;
}

static void populateImageContainerConfig(ImageContainerConfig& cfg) {
    ImageCfg imageCfg;
    imageCfg.location = "../resources/sprites/running_girl_small.png";
    for (auto i = 0; i < RUNNING_GIRL_FRAMES; ++i) {
        imageCfg.frames.emplace_back(i * RUNNING_GIRL_KEYS_WIDTH, //x
                                     0, //y
                                     RUNNING_GIRL_KEYS_WIDTH, //width
                                     RUNNING_GIRL_KEYS_HEIGHT); //height
    }

    cfg.imageConfigs.emplace(TextureID::RUNNING_GIRL, imageCfg);
    imageCfg.frames.clear();

    imageCfg.location = "../resources/sprites/wheel.png";
    //Calculating position of the running girl
    imageCfg.frames.emplace_back(0, //x
                                 0, //y
                                 WHEEL_IMG_WIDTH, //width
                                 WHEEL_IMG_HEIGHT); //height

    cfg.imageConfigs.emplace(TextureID::WHEEL, imageCfg);
    imageCfg.frames.clear();
}

static void populateTextContainerConfig(TextContainerConfig& cfg){
    FontCfg fontCfg;

    fontCfg.location = "../resources/fonts/AngelineVintage.ttf";
    fontCfg.fontSize = ANGELINE_VINTAGE_40_FONT_SIZE;
    cfg.fontConfigs.insert(std::make_pair(FontId::ANGELINE_VINTAGE_40, fontCfg));
}

static void populateMonitorConfig(MonitorWindowCfg& cfg){
    cfg.windowName = WINDOW_NAME;
    cfg.windowWidth = WINDOW_WIDTH;
    cfg.windowHeight = WINDOW_HEIGTH;
    cfg.windowFlags = WINDOW_SHOWN;
}

static void populateResMgrConfig(ResMgrCfg& cfg){
    populateImageContainerConfig(cfg.imageContainerCfg);
    populateTextContainerConfig(cfg.textContainerCfg);
}

static void populateDrawMgrConfig(DrawMgrCfg& cfg){
    populateMonitorConfig(cfg.windowCfg);
    cfg.maxFrameRate = MAX_FRAMERATE;
}

static void populateMgrHandlerCfgConfig(MgrHandlerCfg& cfg){
    populateDrawMgrConfig(cfg.drawMgrCfg);
    populateResMgrConfig(cfg.resMgrCfg);
}

static void populateGameConfig(GameCfg& cfg){
    cfg.runningGirlRsrcId = TextureID::RUNNING_GIRL;
    cfg.wheelRsrcId = TextureID::WHEEL;

    cfg.textFontId = FontId::ANGELINE_VINTAGE_40;
}


EngineConfig EngineConfigLoader::loadConfig(){
    EngineConfig cfg;

    populateMgrHandlerCfgConfig(cfg.mgrHandlerCfg);
    populateGameConfig(cfg.gameCfg);

    return cfg;
}
