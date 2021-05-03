cmake_minimum_required(VERSION 3.19)
project(SDL2_Learning C)

set(CMAKE_C_STANDARD 99)

add_executable(SDL2_Learning Game/GameMain.c Engine/egSDLController.h Engine/egSDLController.c Engine/egSDLContext.h Engine/egSDLGame.h Engine/egSDLControllerRuntime.c Engine/egSDLControllerRuntime.h Game/GameBase.h Engine/EngineInclude.h Game/GameBase.c Engine/Objects/egSprite.h Engine/Objects/egSprite.c Engine/Objects/egColor3.h Engine/Objects/Vector2.h Engine/Objects/Vector2.c Engine/Objects/egSpriteList.h Engine/Objects/egSpriteList.c Engine/Objects/egSpriteManager.h Engine/Objects/egSpriteManager.c)

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})
