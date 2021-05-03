//
// Created by eevee on 28.04.21.
//


#ifndef SDL2_LEARNING_GAMEBASE_H
#define SDL2_LEARNING_GAMEBASE_H

#include "../Engine/egSDLContext.h"

#include <SDL.h>

void GameBase_Initialize(struct egSDLContext* context);
void GameBase_Update(struct egSDLContext* context);
void GameBase_Draw(double delta, struct egSDLContext* context);
void GameBase_OnClose(struct egSDLContext* context);
void GameBase_OnSdlEvent(SDL_Event event);

#endif //SDL2_LEARNING_GAMEBASE_H
