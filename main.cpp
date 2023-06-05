#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <string>

#define _HAVE_STDINT_H 1

#include "build/engine/Engine.h"
#include "sdl_utils/SDLLoader.h"
#include "build/engine/EngineConfigLoader.h"

static int32_t runApplication(){
   Engine engine;

    InputEvent event;
    event.init();

    if(EXIT_SUCCESS != engine.init(EngineConfigLoader::loadConfig())){
        throw std::invalid_argument("engine.init() failed.");
    }

    engine.start();

    engine.deinit();

    return EXIT_SUCCESS;
}

int32_t main([[maybe_unused]] int32_t argc, [[maybe_unused]] char* argv[]){

    if(EXIT_SUCCESS != SDLLoader::init()){
        throw std::invalid_argument("SDL_Init() failed.");
    }

    if(EXIT_SUCCESS != runApplication()){
        throw std::invalid_argument("runApplication() failed.");
    }

    SDLLoader::deinit();
    
    std::cout << "I successed to push the change." << std::endl;

    return EXIT_SUCCESS;
}



