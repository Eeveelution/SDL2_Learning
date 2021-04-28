//
// Created by eevee on 28.04.21.
//
#include "SDLController.h"

//Initializes SDL
bool SdlController_Init(struct SDLContext* context) {
    bool success = true;
    
    //Initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("SDL failed to Initialize; SDL_Error: %s\n", SDL_GetError());
        success = false;
    } else {
        context->window = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, SDL_WINDOW_SHOWN);
        
        if(context->window == NULL){
            printf("Failed to Create SDL Window, SDL_Error: %s\n", SDL_GetError());
            success = false;
        } else {
            context->screenSurface = SDL_GetWindowSurface(context->window);
        }
    }
    
    return success;
}

//Loads an Image and returns
SDL_Surface *SdlController_LoadImage(char *filename) {
    SDL_Surface* image = SDL_LoadBMP(filename);
    
    return image;
}

//Disposes and Deletes everything SDL Related
void SdlController_Close(struct SDLContext* context) {
    //TODO: Store all Loaded Image Pointers and Free them Here
    
    SDL_DestroyWindow(context->window);
    SDL_Quit();
}
