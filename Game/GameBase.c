//
// Created by eevee on 28.04.21.
//

#include "GameBase.h"

SDL_Texture* testTexture = NULL;

void GameBase_Initialize(struct SDLContext* context){
    testTexture = SdlController_LoadImage("test.png");
}

void GameBase_Update(struct SDLContext *context) {
    printf("hi");
}

void GameBase_Draw(double delta, struct SDLContext *context) {
    SDL_RenderClear(context->renderer);

    SDL_RenderCopy(context->renderer, testTexture, NULL, NULL);

    SDL_RenderPresent(context->renderer);
}

void GameBase_OnClose(struct SDLContext *context) {
    SDL_DestroyTexture(testTexture);
    testTexture = NULL;
}

void GameBase_OnSdlEvent(SDL_Event event) {

}

