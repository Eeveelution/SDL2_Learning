//
// Created by eevee on 28.04.21.
//
#include <SDL2/SDL.h>
#include "SDL_image.h"

#include <stdbool.h>

#include "egSDLContext.h"
#include "egSDLGame.h"

#ifndef SDL2_LEARNING_SDLCONTROLLER_H
#define SDL2_LEARNING_SDLCONTROLLER_H

#define CONTROLLER_IMAGE_FLAGS IMG_INIT_PNG

bool egSdlController_Init(struct egSDLContext* context);
void egSdlController_Close(struct egSDLContext* context);

SDL_Texture *egSdlController_LoadImage(struct egSDLContext* context, char *filename);

#endif //SDL2_LEARNING_SDLCONTROLLER_H
