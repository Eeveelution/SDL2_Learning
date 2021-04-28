#include <stdio.h>

#include <SDL2/SDL.h>

int main() {
    SDL_Window*  window = NULL;
    SDL_Surface* screenSurface = NULL;
    
    //Initializing
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("SDL failed to Initialize; SDL_Error: %s\n", SDL_GetError());
    } else {
        window = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, SDL_WINDOW_SHOWN);
        
        if(window == NULL) {
            printf("Failed to Create SDL Window, SDL_Error: %s\n", SDL_GetError());
        } else {
            screenSurface = SDL_GetWindowSurface(window);
            
            
    
            SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xff, 0xff, 0xff));
    
            SDL_UpdateWindowSurface(window);
    
    
            SDL_Delay(15000);
        }
    }
    
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
