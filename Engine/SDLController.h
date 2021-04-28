//
// Created by eevee on 28.04.21.
//
#include <SDL2/SDL.h>

#include <stdbool.h>

#include "Objects/SDLContext.h";

#ifndef SDL2_LEARNING_SDLCONTROLLER_H
#define SDL2_LEARNING_SDLCONTROLLER_H

bool SdlController_Init(struct SDLContext* context);
void SdlController_Close();

SDL_Surface* SdlController_LoadImage(char* filename);

#endif //SDL2_LEARNING_SDLCONTROLLER_H
