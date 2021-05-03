//
// Created by eevee on 28.04.21.
//

#ifndef SDL2_LEARNING_EGSPRITE_H
#define SDL2_LEARNING_EGSPRITE_H

#include <SDL.h>
#include <SDL_image.h>

#include <stdbool.h>

#include "Vector2.h"
#include "egColor3.h"
#include "../egSDLContext.h"

struct egSprite {
    SDL_Texture *spriteTexture;
    
    struct Vector2 spriteSize;
    struct Vector2 spriteLocation;
    
    double rotationAngle;
    struct Vector2 centerPoint;
    
    SDL_RendererFlip rendererFlip;
    
    double drawDepth;
    
    bool isClickable;
    
    int spriteTag;
};

struct egSprite* Sprite_NewSpriteEmpty();
struct egSprite* Sprite_NewSpriteTextured(struct egSDLContext *context, char *imageFilename, egColor3 colorKey);

void Sprite_LoadImage(struct egSprite *sprite, struct egSDLContext *context, char *imageFilename, egColor3 colorKey);
void Sprite_Draw(struct egSprite *sprite, struct egSDLContext *context);
void Sprite_DrawClipped(struct egSprite *sprite, struct egSDLContext *context, SDL_Rect *clip);

void Sprite_SetLocation(struct egSprite *sprite, struct Vector2 position);
void Sprite_SetColor(struct egSprite *sprite, egColor3 color);
void Sprite_SetAlpha(struct egSprite *sprite, uint8_t alpha);
void Sprite_SetCenterPoint(struct egSprite *sprite, struct Vector2 point);
void Sprite_SetRotation(struct egSprite *sprite, double angle);
void Sprite_SetFlip(struct egSprite *sprite, SDL_RendererFlip flip);

void Sprite_SetClickable(struct egSprite *sprite, bool clickable);

void Sprite_Free(struct egSprite *sprite);

#endif //SDL2_LEARNING_EGSPRITE_H
