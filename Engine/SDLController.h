//
// Created by eevee on 28.04.21.
//
#include <SDL2/SDL.h>

#include <stdbool.h>

#include "Objects/SDLContext/SDLContext.h"
#include "SDLGame.h"

#ifndef SDL2_LEARNING_SDLCONTROLLER_H
#define SDL2_LEARNING_SDLCONTROLLER_H

bool SdlController_Init(struct SDLContext* context);
void SdlController_Close(struct SDLContext* context);

SDL_Surface* SdlController_LoadImage(char* filename);

void SdlController_StartGame(struct SDLContext* context, struct SDLGame* game);

#endif //SDL2_LEARNING_SDLCONTROLLER_H
