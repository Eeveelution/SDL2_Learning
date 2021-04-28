//
// Created by eevee on 28.04.21.
//
#include <SDL2/SDL.h>
#include "SDL_image.h"

#include <stdbool.h>

#include "SDLContext.h"
#include "SDLGame.h"

#ifndef SDL2_LEARNING_SDLCONTROLLER_H
#define SDL2_LEARNING_SDLCONTROLLER_H

#define CONTROLLER_IMAGE_FLAGS IMG_INIT_PNG


bool SdlController_Init(struct SDLContext* context);
void SdlController_Close(struct SDLContext* context);

SDL_Texture *SdlController_LoadImage(struct SDLContext* context, char *filename);

#endif //SDL2_LEARNING_SDLCONTROLLER_H
