//
// Created by eevee on 28.04.21.
//
#include <SDL2/SDL.h>

#include <stdbool.h>

#include "SDLContext.h"
#include "SDLGame.h"

#ifndef SDL2_LEARNING_SDLCONTROLLER_H
#define SDL2_LEARNING_SDLCONTROLLER_H

#define CONTROLLER_IMAGE_FLAGS IMG_INIT_PNG


bool SdlController_Init(struct SDLContext* context);
void SdlController_Close(struct SDLContext* context);

SDL_Surface* SdlController_LoadImage(char* filename);

#endif //SDL2_LEARNING_SDLCONTROLLER_H
