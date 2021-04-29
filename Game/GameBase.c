//
// Created by eevee on 28.04.21.
//

#include "GameBase.h"

struct Sprite *sprite;

void GameBase_Initialize(struct SDLContext* context){
    Color3 colorKey = {0x00, 0x00, 0x00};
    sprite = Sprite_NewSpriteTextured(context, "test.png", colorKey);
    
    struct Vector2 position = {128, 128};
    
    Sprite_SetLocation(sprite, position);
}

void GameBase_Update(struct SDLContext *context) {

}

void GameBase_Draw(double delta, struct SDLContext *context) {
    SDL_SetRenderDrawColor(context->renderer, 0xff, 0xff, 0xff, 0xff);
    SDL_RenderClear(context->renderer);
    
    Sprite_Draw(sprite, context);

    SDL_RenderPresent(context->renderer);
}

void GameBase_OnClose(struct SDLContext *context) {
    Sprite_Free(sprite);
}

void GameBase_OnSdlEvent(SDL_Event event) {

}

