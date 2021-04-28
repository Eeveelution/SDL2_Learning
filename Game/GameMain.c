#include <stdio.h>

#include <SDL2/SDL.h>

#include "../Engine/SDLController.h"
#include "../Engine/SDLContext.h"

#include "GameBase.h"

int main() {
    struct SDLContext ctx;
    
    if(!SdlController_Init(&ctx)){
        return -1;
    } else {
        struct SDLGame game;

        game.Initialize = GameBase_Initialize;
        game.Draw = GameBase_Draw;
        game.OnClose = GameBase_OnClose;
        game.Update = GameBase_Update;
        game.OnSdlEvent = GameBase_OnSdlEvent;
    
        SdlControllerRuntime_RunGame(&ctx, &game);
    }

    return 0;
}
