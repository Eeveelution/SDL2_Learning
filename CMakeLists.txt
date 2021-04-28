cmake_minimum_required(VERSION 3.19)
project(SDL2_Learning C)

set(CMAKE_C_STANDARD 99)

add_executable(SDL2_Learning main.c Engine/SDLController.h Engine/SDLController.c Engine/Objects/SDLContext/SDLContext.h)

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})
