#include <stdio.h>

#include <SDL2/SDL.h>

#include "Engine/SDLController.h"
#include "Engine/Objects/SDLContext/SDLContext.h"

int main() {
    struct SDLContext ctx;
    
    if(!SdlController_Init(&ctx)){
        return -1;
    } else {
        SDL_Surface *image = SdlController_LoadImage("test.bmp");
        
        if(image != NULL){
            SDL_BlitSurface(image, NULL, ctx.screenSurface, NULL);
    
            SDL_UpdateWindowSurface(ctx.window);
    
            SDL_Delay(15000);
        }
    }

    return 0;
}
