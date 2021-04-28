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
            bool run = true;
            //Stores Currently Looping Event
            SDL_Event event;
            
            while(run){
                //Poll Events
                while(SDL_PollEvent(&event) != 0) {
                    if (event.type == SDL_QUIT) {
                        run = false;
                    }
                }
                
                SDL_BlitSurface(image, NULL, ctx.screenSurface, NULL);
                SDL_UpdateWindowSurface(ctx.window);
            }
        }
    }

    return 0;
}
