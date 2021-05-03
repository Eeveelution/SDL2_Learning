//
// Created by eevee on 28.04.21.
//

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wvisibility"
#ifndef SDL2_LEARNING_SDLGAME_H
#define SDL2_LEARNING_SDLGAME_H

#include "SDL.h"
#include "Objects/Vector2.h"

struct egSDLGame {
    void (*Initialize)(struct egSDLContext* context);
    void (*Update)(struct egSDLContext* context);
    void (*Draw)(double deltaTime, struct egSDLContext* context);
    void (*OnClose)(struct egSDLContext* context);
    void (*OnSDLEvent)(SDL_Event event);
    void (*OnMouseHover)(struct Vector2 point);
    void (*OnMouseClick)(struct Vector2 point);
};

#endif //SDL2_LEARNING_SDLGAME_H