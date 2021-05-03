//
// Created by eevee on 28.04.21.
//

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wvisibility"
#ifndef SDL2_LEARNING_SDLGAME_H
#define SDL2_LEARNING_SDLGAME_H

#include "SDL.h"

struct egSDLGame {
    void (*Initialize)(struct egSDLContext* context);
    void (*Update)(struct egSDLContext* context);
    void (*Draw)(double deltaTime, struct egSDLContext* context);
    void (*OnClose)(struct egSDLContext* context);
    void (*OnKeyDown)(SDL_Event event);
    void (*OnMouseEvent)(SDL_Event event);
};

#endif //SDL2_LEARNING_SDLGAME_H