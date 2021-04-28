//
// Created by eevee on 28.04.21.
//

#include "Sprite.h"

struct Sprite *Sprite_NewSpriteEmpty() {
    struct Sprite *sprite = malloc(sizeof(struct Sprite));
    
    sprite->spriteTexture = NULL;
    sprite->spriteWidth = 0;
    sprite->spriteHeight = 0;
    
    return sprite;
}

void Sprite_LoadImage(struct Sprite *sprite, struct SDLContext *context, char *imageFilename, Color3_t colorKey) {
    SDL_Texture *texture = NULL;
    
    SDL_Surface *loadedSurface = IMG_Load(imageFilename);
    
    if(loadedSurface == NULL){
        printf("$[WARNING] Failed to load image `%s`; SDL_Image_Error: %s", imageFilename, IMG_GetError());
        return;
    } else {
        SDL_SetColorKey(loadedSurface, SDK_True, SDL_MapRGB(loadedSurface->format, colorKey.r, colorKey.g, colorKey.b));
        
        texture = SDL_CreateTextureFromSurface(context->renderer, loadedSurface);
        
        if(texture == NULL){
            printf("$[WARNING] Failed to create Texture out of `%s`; SDL_Error: %s", imageFilename, SDL_GetError());
            return;
        } else {
            sprite->spriteWidth = loadedSurface->w;
            sprite->spriteHeight = loadedSurface->h;
        }
    
        SDL_FreeSurface(loadedSurface);
    }
}


