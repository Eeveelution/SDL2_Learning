//
// Created by eevee on 28.04.21.
//

#ifndef SDL2_LEARNING_SPRITE_H
#define SDL2_LEARNING_SPRITE_H

#include <SDL.h>
#include <SDL_image.h>

#include "../EngineInclude.h"

#include "Vector2.h"
#include "Color3.h"

struct Sprite {
    SDL_Texture *spriteTexture;
    struct Vector2 spriteSize;
    struct Vector2 spriteLocation;
    
};

struct Sprite* Sprite_NewSpriteEmpty();
struct Sprite* Sprite_NewSpriteTextured(struct SDLContext *context, char *imageFilename, Color3 colorKey);


void Sprite_LoadImage(struct Sprite *sprite, struct SDLContext *context, char *imageFilename, Color3 colorKey);
void Sprite_Draw(struct Sprite *sprite, struct SDLContext *context);
void Sprite_DrawClipped(struct Sprite *sprite, struct SDLContext *context, SDL_Rect *clip);

void Sprite_SetLocation(struct Sprite *sprite, struct Vector2 position);
void Sprite_SetColor(struct Sprite *sprite, Color3 color);

void Sprite_Free(struct Sprite *sprite);

#endif //SDL2_LEARNING_SPRITE_H
