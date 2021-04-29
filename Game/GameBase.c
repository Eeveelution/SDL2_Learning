//
// Created by eevee on 28.04.21.
//

#include "GameBase.h"

struct Sprite *sprite;

void GameBase_Initialize(struct SDLContext* context){
    Color3 colorKey = {0x01, 0x00, 0x00};
    Color3 testColor = {0xff, 0x00, 0xff};
    sprite = Sprite_NewSpriteTextured(context, "test.png", colorKey);
    
    struct Vector2 position = {0, 0};
    
    Sprite_SetLocation(sprite, position);
}

void GameBase_Update(struct SDLContext *context) {

}

void GameBase_Draw(double delta, struct SDLContext *context) {
    SDL_SetRenderDrawColor(context->renderer, 0xff, 0xff, 0xff, 0xff);
    SDL_RenderClear(context->renderer);
    
    SDL_Rect rect = {256, 128, 256, 128};
    
    Sprite_Draw(sprite, context);
    Sprite_SetFlip(sprite, SDL_FLIP_VERTICAL);

    SDL_RenderPresent(context->renderer);
}

void GameBase_OnClose(struct SDLContext *context) {
    Sprite_Free(sprite);
}

void GameBase_OnSdlEvent(SDL_Event event) {

}

