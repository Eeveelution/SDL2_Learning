//
// Created by eevee on 28.04.21.
//

#include "egSprite.h"

struct egSprite *Sprite_NewSpriteEmpty() {
    struct egSprite *sprite = malloc(sizeof(struct egSprite));
    
    sprite->spriteTexture = NULL;
    
    sprite->spriteSize.x = 0;
    sprite->spriteSize.y = 0;
    
    sprite->spriteLocation.x = 0;
    sprite->spriteLocation.y = 0;
    
    struct Vector2 centerNullPoint = {0, 0};
    
    sprite->centerPoint = centerNullPoint;
    sprite->spriteLocation = centerNullPoint;
    sprite->rotationAngle = 0;
    sprite->rendererFlip = SDL_FLIP_NONE;
    
    return sprite;
}

struct egSprite* Sprite_NewSpriteTextured(struct egSDLContext *context, char *imageFilename, egColor3 colorKey) {
    struct egSprite *sprite = malloc(sizeof(struct egSprite));
    
    Sprite_LoadImage(sprite, context, imageFilename, colorKey);
    
    struct Vector2 centerNullPoint = {0, 0};
    
    sprite->centerPoint = centerNullPoint;
    sprite->spriteLocation = centerNullPoint;
    sprite->rotationAngle = 0;
    sprite->rendererFlip = SDL_FLIP_NONE;
    sprite->isClickable = false;
    sprite->spriteTag = -1;
    sprite->drawDepth = 0.0;
    
    return sprite;
}

void Sprite_LoadImage(struct egSprite *sprite, struct egSDLContext *context, char *imageFilename, egColor3 colorKey) {
    Sprite_Free(sprite);
    
    SDL_Texture *texture = NULL;
    
    SDL_Surface *loadedSurface = IMG_Load(imageFilename);
    
    if(loadedSurface == NULL){
        printf("$[WARNING] Failed to load image `%s`; SDL_Image_Error: %s", imageFilename, IMG_GetError());
        return;
    } else {
        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, colorKey.r, colorKey.g, colorKey.b));
        
        texture = SDL_CreateTextureFromSurface(context->renderer, loadedSurface);
        
        if(texture == NULL){
            printf("$[WARNING] Failed to create Texture out of `%s`; SDL_Error: %s", imageFilename, SDL_GetError());
            return;
        } else {
            sprite->spriteSize.x = loadedSurface->w;
            sprite->spriteSize.y = loadedSurface->h;
        }
    
        SDL_FreeSurface(loadedSurface);
    }
    sprite->spriteTexture = texture;
}

void Sprite_Free(struct egSprite *sprite) {
    if(sprite->spriteTexture != NULL){
        SDL_DestroyTexture(sprite->spriteTexture);
        
        sprite->spriteTexture = NULL;
        
        sprite->spriteSize.x = 0;
        sprite->spriteSize.y = 0;
    }
}

void Sprite_Draw(struct egSprite *sprite, struct egSDLContext *context) {
    SDL_Rect renderRect = { sprite->spriteLocation.x, sprite->spriteLocation.y, sprite->spriteSize.x, sprite->spriteSize.y };
    
    SDL_RenderCopyEx(context->renderer, sprite->spriteTexture, NULL, &renderRect, sprite->rotationAngle,
                   Vector2_ToPoint(&sprite->centerPoint), sprite->rendererFlip);
}

void Sprite_DrawClipped(struct egSprite *sprite, struct egSDLContext *context, SDL_Rect *clip){
    SDL_Rect renderRect = { sprite->spriteLocation.x, sprite->spriteLocation.y, sprite->spriteSize.x, sprite->spriteSize.y };
    
    //Only Apply if clip isn't null
    if(clip != NULL) {
        renderRect.w = clip->w;
        renderRect.h = clip->h;
    }
    
    SDL_RenderCopyEx(context->renderer, sprite->spriteTexture, clip, &renderRect, sprite->rotationAngle,
                     Vector2_ToPoint(&sprite->centerPoint), sprite->rendererFlip);
}

void Sprite_SetLocation(struct egSprite *sprite, struct Vector2 position) {
    sprite->spriteLocation = position;
}

void Sprite_SetColor(struct egSprite *sprite, egColor3 color) {
    SDL_SetTextureColorMod(sprite->spriteTexture, color.r, color.g, color.b);
}

void Sprite_SetAlpha(struct egSprite *sprite, uint8_t alpha) {
    SDL_SetTextureAlphaMod(sprite->spriteTexture, alpha);
}

void Sprite_SetCenterPoint(struct egSprite *sprite, struct Vector2 point) {
    sprite->centerPoint = point;
}
void Sprite_SetRotation(struct egSprite *sprite, double angle) {
    sprite->rotationAngle = angle;
}

void Sprite_SetFlip(struct egSprite *sprite, SDL_RendererFlip flip) {
    sprite->rendererFlip = flip;
}

void Sprite_SetClickable(struct egSprite *sprite, bool clickable) {
    sprite->isClickable = clickable;
}
