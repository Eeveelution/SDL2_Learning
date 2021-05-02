//
// Created by eevee on 02.05.21.
//

#include "SpriteManager.h"

void egSpriteManager_Draw(struct SpriteManager *manager, struct SDLContext *context) {
    for(int i = 0; i != manager->spriteList->size - 1; i++){
        Sprite_Draw(&manager->spriteList->list[i], context);
    }
}

