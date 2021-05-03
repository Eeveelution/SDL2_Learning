#include <stdio.h>

#include <SDL2/SDL.h>

#include "../Engine/egSDLController.h"
#include "../Engine/egSDLContext.h"

#include "GameBase.h"
#include "../Engine/egSDLControllerRuntime.h"

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
        game.OnKeyDown = GameBase_OnSdlEvent;
    
        egSdlControllerRuntime_RunGame(&ctx, &game);
    }

    return 0;
}
