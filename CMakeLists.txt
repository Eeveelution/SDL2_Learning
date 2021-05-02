cmake_minimum_required(VERSION 3.19)
project(SDL2_Learning C)

set(CMAKE_C_STANDARD 99)

add_executable(SDL2_Learning Game/GameMain.c Engine/SDLController.h Engine/SDLController.c Engine/SDLContext.h Engine/SDLGame.h Engine/SDLControllerRuntime.c Engine/SDLControllerRuntime.h Game/GameBase.h Engine/EngineInclude.h Game/GameBase.c Engine/Objects/Sprite.h Engine/Objects/Sprite.c Engine/Objects/Color3.h Engine/Objects/Vector2.h Engine/Objects/Vector2.c Engine/Objects/SpriteList.h Engine/Objects/SpriteList.c Engine/Objects/SpriteManager.h Engine/Objects/SpriteManager.c)

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})
