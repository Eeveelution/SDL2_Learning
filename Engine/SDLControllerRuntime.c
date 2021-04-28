//
// Created by eevee on 28.04.21.
//

#include "SDLControllerRuntime.h"

void SdlControllerRuntime_RunGame(struct SDLContext *context, struct SDLGame *game) {
    bool run = true;
    //Stores Currently Looping Event
    SDL_Event event;
    //Stores Timers for DeltaTime Calculation
    Uint64 delta_now = SDL_GetPerformanceCounter();
    Uint64 delta_last = 0;
    
    double delta_time = 0;
    
    while(run){
        //Poll Events
        while(SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                run = false;
            } else {
                game->OnSdlEvent(event);
            }
        }
        
        game->Update(context);
        
        //Update Delta Time
        delta_last = delta_now;
        delta_now = SDL_GetPerformanceCounter();
        delta_time = (double)((delta_now - delta_last) * 1000.0 / (double)SDL_GetPerformanceFrequency());
        
        game->Draw(delta_time, context);
    }
    
    game->OnClose();
}

