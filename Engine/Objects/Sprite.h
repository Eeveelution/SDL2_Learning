//
// Created by eevee on 28.04.21.
//

#ifndef SDL2_LEARNING_SPRITE_H
#define SDL2_LEARNING_SPRITE_H

#include <SDL.h>
#include <SDL_image.h>

#include "../EngineInclude.h"

#include "Vector2.h"

struct Sprite {
    SDL_Texture *spriteTexture;
    struct Vector2 spriteSize;
    struct Vector2 spriteLocation;
    
} Sprite;

struct Sprite* Sprite_NewSpriteEmpty();

void Sprite_LoadImage(struct Sprite *sprite, struct SDLContext *context, char *imageFilename, Color3_t colorKey);
void Sprite_Draw(struct Sprite *sprite, struct SDLContext *context);
void Sprite_SetLocation(struct Sprite *sprite, int x, int y);
void Sprite_Free(struct Sprite *sprite);

#endif //SDL2_LEARNING_SPRITE_H
