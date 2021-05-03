#include <stdio.h>

#include <SDL2/SDL.h>

#include "../Engine/SDLController.h"
#include "../Engine/egSDLContext.h"

#include "GameBase.h"

int main() {
    struct egSDLContext ctx;
    
    if(!egSdlController_Init(&ctx)){
        return -1;
    } else {
        struct egSDLGame game;

        game.Initialize = GameBase_Initialize;
        game.Draw = GameBase_Draw;
        game.OnClose = GameBase_OnClose;
        game.Update = GameBase_Update;
        game.OnSdlEvent = GameBase_OnSdlEvent;
    
        SdlControllerRuntime_RunGame(&ctx, &game);
    }

    return 0;
}
