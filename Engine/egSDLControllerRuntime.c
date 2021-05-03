//
// Created by eevee on 28.04.21.
//

#include "egSDLControllerRuntime.h"

void egSdlControllerRuntime_RunGame(struct egSDLContext *context, struct egSDLGame *game) {
    //Let the Game Initialize
    game->Initialize(context);
    
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
            //Handle Events
            switch(event.type) {
                case SDL_QUIT: {
                    run = false;
                    break;
                }
                case SDL_MOUSEMOTION: {
                    int x, y;
                    SDL_GetMouseState(&x, &y);
                    struct Vector2 mousePoint = {x, y};
    
                    game->OnMouseHover(mousePoint);
                    break;
                }
                case SDL_MOUSEBUTTONDOWN: {
                    int x, y;
                    SDL_GetMouseState(&x, &y);
                    struct Vector2 mousePoint = {x, y};
    
                    game->OnMouseClick(mousePoint);
                    break;
                }
                default:
                    game->OnSDLEvent(event);
                
            }
        
        game->Update(context);
        
        //GameBase_Update Delta Time
        delta_last = delta_now;
        delta_now = SDL_GetPerformanceCounter();
        delta_time = (double)((delta_now - delta_last) * 1000.0 / (double)SDL_GetPerformanceFrequency());
        
        game->Draw(delta_time, context);
    }
    //Close everything Down
    game->OnClose(context);
    egSdlController_Close(context);
}

