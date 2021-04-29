//
// Created by eevee on 28.04.21.
//
#include "SDLController.h"

//Initializes SDL
bool SdlController_Init(struct SDLContext* context) {
    bool success = true;
    
    //Initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("$[FATAL] SDL failed to Initialize; SDL_Error: %s\n", SDL_GetError());
        success = false;
    } else {
        if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")){
            printf("$[WARNING] Failed to enable Linear Texture filtering.");
        }
        //Creating Window
        context->window = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, SDL_WINDOW_SHOWN);
        
        if(context->window == NULL){
            printf("$[FATAL] Failed to Create SDL Window, SDL_Error: %s\n", SDL_GetError());
            success = false;
        } else {
            //Creating Renderer
            context->renderer = SDL_CreateRenderer(context->window, -1, SDL_RENDERER_ACCELERATED);

            if(context->renderer == NULL){
                printf("$[FATAL] Failed to create SDL Renderer, SDL_Error: %s\n", SDL_GetError());
                success = false;
            } else {
                //Initializing Renderer Color
                SDL_SetRenderDrawColor(context->renderer, 0xff, 0xff, 0xff, 0xff);

                //Initialize PNG Loading
                if(!(IMG_Init(CONTROLLER_IMAGE_FLAGS) & CONTROLLER_IMAGE_FLAGS)){
                    printf("$[FATAL] Failed initialize SDL_Image PNG loading, SDL_image_Error: %s\n", IMG_GetError());
                    success = false;
                }
            }
        }
    }
    
    return success;
}

//Loads an Image and returns
SDL_Texture *SdlController_LoadImage(struct SDLContext* context, char *filename) {
    SDL_Texture* finalTexture = NULL;

    //Load Image
    SDL_Surface* loadedSurface = IMG_Load(filename);

    if(loadedSurface == NULL){
        printf("![WARNING] Failed to load image `%s` SDL_Image_Error: %s\n", filename, IMG_GetError());
        return NULL;
    } else {
        finalTexture = SDL_CreateTextureFromSurface(context->renderer, loadedSurface);

        if(finalTexture == NULL){
            printf("![WARNING] Failed to crete texture from `%s`, SDL_Image_Error: %s", filename, SDL_GetError());
        }

        SDL_FreeSurface(loadedSurface);
    }
    return finalTexture;
}

//Disposes and Deletes everything SDL Related
void SdlController_Close(struct SDLContext* context) {
    //TODO: Store all Loaded Image Pointers and Free them Here
    
    SDL_DestroyWindow(context->window);
    SDL_DestroyRenderer(context->renderer);

    context->renderer = NULL;
    context->window = NULL;

    IMG_Quit();
    SDL_Quit();
}
