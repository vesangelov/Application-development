cmake_minimum_required(VERSION 3.5.1)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake_helpers/helpers.cmake)

project(text_and_colors LANGUAGES CXX)

#if(UNIX)
#set(SDL2_image_name SDL2_image)
#set(SDL2_ttf_name SDL2_ttf)
#set(SDL2_mixer_name SDL2_mixer)

#elseif(WIN32 OR APPLE)
#set(SDL2_image_name SDL2_IMAGE)
#set(SDL2_ttf_name SDL2_TTF)
#set(SDL2_mixer_name SDL2_MIXER)
#endif()

#find_package(SDL2 REQUIRED)
#find_package(${SDL2_image_name} REQUIRED)
#find_package(${SDL2_image_name} REQUIRED)
#find_package(${SDL2_mixer_name} REQUIRED)

set(_BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(
    ${PROJECT_NAME}
            ${_BASE_DIR}/utils/drawing/Point.h
            ${_BASE_DIR}/utils/drawing/Point.cpp

            ${_BASE_DIR}/utils/drawing/Rectangle.h
            ${_BASE_DIR}/utils/drawing/Rectangle.cpp

            ${_BASE_DIR}/utils/drawing/Color.h
            ${_BASE_DIR}/utils/drawing/Color.cpp

            ${_BASE_DIR}/utils/thread/ThreadUtils.h
            ${_BASE_DIR}/utils/thread/ThreadUtils.cpp

            ${_BASE_DIR}/sdl_utils/SDLLoader.h
            ${_BASE_DIR}/sdl_utils/SDLLoader.cpp

            ${_BASE_DIR}/sdl_utils/MonitorWindow.h
            ${_BASE_DIR}/sdl_utils/MonitorWindow.cpp

            ${_BASE_DIR}/sdl_utils/Texture.h
            ${_BASE_DIR}/sdl_utils/Texture.cpp

            ${_BASE_DIR}/sdl_utils/InputEvent.h
            ${_BASE_DIR}/sdl_utils/InputEvent.cpp

            ${_BASE_DIR}/sdl_utils/Renderer.h
            ${_BASE_DIR}/sdl_utils/Renderer.cpp

            ${_BASE_DIR}/sdl_utils/containers/ImageContainer.h
            ${_BASE_DIR}/sdl_utils/containers/ImageContainer.cpp
            ${_BASE_DIR}/sdl_utils/containers/TextContainer.h
            ${_BASE_DIR}/sdl_utils/containers/TextContainer.cpp
            ${_BASE_DIR}/sdl_utils/Renderer.cpp

            ${_BASE_DIR}/build/engine/Engine.h
            ${_BASE_DIR}/build/engine/Engine.cpp

            ${_BASE_DIR}/game/Game.h
            ${_BASE_DIR}/game/Game.cpp
            ${_BASE_DIR}/game/config/GameCfg.h

            ${_BASE_DIR}/build/engine/config/EngineConfig.h
            ${_BASE_DIR}/build/engine/EngineConfigLoader.h
            ${_BASE_DIR}/build/engine/EngineConfigLoader.cpp

            ${_BASE_DIR}/sdl_utils/config/MonitorWindowCfg.h
            ${_BASE_DIR}/sdl_utils/config/ImageContainerCfg.h
            ${_BASE_DIR}/sdl_utils/config/TextContainerCfg.h

            ${_BASE_DIR}/utils/input/EventDefines.h
            ${_BASE_DIR}/utils/drawing/DrawParams.h
            ${_BASE_DIR}/common/CommonDefines.h

            ${_BASE_DIR}/main.cpp)

set_target_cpp_standard(${PROJECT_NAME} 17)
enable_target_warnings(${PROJECT_NAME})

if(UNIX)
target_link_libraries(${PROJECT_NAME} PUBLIC SDL2 SDL2_image SDL2_ttf SDL2_mixer)

elseif(WIN32 OR APPLE)
target_link_libraries(${PROJECT_NAME} PUBLIC SDL2 SDL2_IMAGE SDL2_TTF SDL2_MIXER)
endif()

target_include_directories(${PROJECT_NAME} 
                          PRIVATE
                          ${SDL2_INCLUDE_DIR}
                          ${SDL2_IMAGE_INCLUDE_DIR}
                          ${SDL2_TTF_INCLUDE_DIR}
                          ${SDL2_MIXER_INCLUDE_DIR})

target_link_directories(${PROJECT_NAME} 
                          PRIVATE
                          ${SDL2_INCLUDE_DIR}
                          ${SDL2_IMAGE_INCLUDE_DIR}
                          ${SDL2_TTF_INCLUDE_DIR}
                          ${SDL2_MIXER_INCLUDE_DIR})
