//
// Created by eevee on 28.04.21.
//

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wvisibility"
#ifndef SDL2_LEARNING_SDLGAME_H
#define SDL2_LEARNING_SDLGAME_H

#include "SDL.h"

struct SDLGame {
    void (*Initialize)(struct SDLContext* context);
    void (*Update)(struct SDLContext* context);
    void (*Draw)(double deltaTime, struct SDLContext* context);
    void (*OnClose)(struct SDLContext* context);
    void (*OnSdlEvent)(SDL_Event event);
};

#endif //SDL2_LEARNING_SDLGAME_H