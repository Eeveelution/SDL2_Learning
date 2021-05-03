//
// Created by eevee on 28.04.21.
//

#include "GameBase.h"

#include "../Engine/Objects/egColor3.h"
#include "../Engine/Objects/egSprite.h"

struct egSprite *sprite;

void GameBase_Initialize(struct egSDLContext* context){
    egColor3 colorKey = {0x01, 0x00, 0x00};
    egColor3 testColor = {0xff, 0x00, 0xff};
    sprite = egSprite_NewSpriteTextured(context, "test.png", colorKey, true);
    
    struct Vector2 position = {0, 0};
    
    egSprite_SetLocation(sprite, position);
}

void GameBase_Update(struct egSDLContext *context) {

}

void GameBase_Draw(double delta, struct egSDLContext *context) {
    SDL_SetRenderDrawColor(context->renderer, 0xff, 0xff, 0xff, 0xff);
    SDL_RenderClear(context->renderer);
    
    SDL_Rect rect = {256, 128, 256, 128};
    
    egSprite_Draw(sprite, context);
    egSprite_SetFlip(sprite, SDL_FLIP_VERTICAL);

    SDL_RenderPresent(context->renderer);
}

void GameBase_OnClose(struct egSDLContext *context) {
    Sprite_Free(sprite);
}

void GameBase_OnSdlEvent(SDL_Event event) {

}

