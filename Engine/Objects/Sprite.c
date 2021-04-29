//
// Created by eevee on 28.04.21.
//

#include "Sprite.h"

struct Sprite *Sprite_NewSpriteEmpty() {
    struct Sprite *sprite = malloc(sizeof(struct Sprite));
    
    sprite->spriteTexture = NULL;
    
    sprite->spriteSize.x = 0;
    sprite->spriteSize.y = 0;
    
    sprite->spriteLocation.x = 0;
    sprite->spriteLocation.y = 0;
    
    return sprite;
}

struct Sprite* Sprite_NewSpriteTextured(struct SDLContext *context, char *imageFilename, Color3 colorKey) {
    struct Sprite *sprite = malloc(sizeof(struct Sprite));
    
    Sprite_LoadImage(sprite, context, imageFilename, colorKey);
    
    return sprite;
}

void Sprite_LoadImage(struct Sprite *sprite, struct SDLContext *context, char *imageFilename, Color3 colorKey) {
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

void Sprite_Free(struct Sprite *sprite) {
    if(sprite->spriteTexture != NULL){
        SDL_DestroyTexture(sprite->spriteTexture);
        
        sprite->spriteTexture = NULL;
        
        sprite->spriteSize.x = 0;
        sprite->spriteSize.y = 0;
    }
}

void Sprite_Draw(struct Sprite *sprite, struct SDLContext *context) {
    SDL_Rect renderRect = { sprite->spriteLocation.x, sprite->spriteLocation.y, sprite->spriteSize.x, sprite->spriteSize.y };
    
    SDL_RenderCopy(context->renderer, sprite->spriteTexture, NULL, &renderRect);
}

void Sprite_SetLocation(struct Sprite *sprite, struct Vector2 position) {
    sprite->spriteLocation = position;
}
