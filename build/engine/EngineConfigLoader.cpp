#include "EngineConfigLoader.h"
#include "../../common/CommonDefines.h"

namespace {
    constexpr auto WINDOW_WIDTH = 800;
    constexpr auto WINDOW_HEIGTH = 680;
    constexpr auto WINDOW_NAME = "Scale and alpha blending";

    constexpr auto PRESS_KEYS_WIDTH = 640;
    constexpr auto PRESS_KEYS_HEIGHT = 480;

    constexpr auto LAYER_2_IMG_WIDTH = 150;
    constexpr auto LAYER_2_IMG_HEIGHT = 150;

    constexpr auto ANGELINE_VINTAGE_40_FONT_SIZE = 40;

    constexpr auto MAX_FRAMERATE = 30;
}

static void populateImageContainerConfig(ImageContainerConfig& cfg) {
    ImageCfg imageCfg;
    imageCfg.location = "../resources/pictures/layer_2.png";
    imageCfg.width = LAYER_2_IMG_WIDTH;
    imageCfg.height = LAYER_2_IMG_HEIGHT;
    cfg.imageConfigs.insert(std::make_pair(TextureID::LAYER_2, imageCfg));

    imageCfg.location = "../resources/pictures/press_keys.png";
    imageCfg.width = PRESS_KEYS_WIDTH;
    imageCfg.height = PRESS_KEYS_HEIGHT;
    cfg.imageConfigs.insert(std::make_pair(TextureID::PRESS_KEYS, imageCfg));
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

static void populateGameConfig(GameCfg& cfg){
    cfg.layer2RsrcId = TextureID::LAYER_2;
    cfg.pressKeysRsrcId = TextureID::PRESS_KEYS;

    cfg.textFontId = FontId::ANGELINE_VINTAGE_40;
}


EngineConfig EngineConfigLoader::loadConfig(){
    EngineConfig cfg;

    populateDrawMgrConfig(cfg.drawMgrCfg);
    populateResMgrConfig(cfg.resMgrCfg);
    populateGameConfig(cfg.gameCfg);

    return cfg;
}
