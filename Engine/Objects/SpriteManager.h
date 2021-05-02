//
// Created by eevee on 02.05.21.
//

#ifndef SDL2_LEARNING_SPRITEMANAGER_H
#define SDL2_LEARNING_SPRITEMANAGER_H

#include "../SDLContext.h"
#include "Sprite.h"

struct SpriteManager {
    struct SpriteList *spriteList;
};

void egSpriteManager_Draw(struct SpriteManager *manager, struct SDLContext *context);

void egSpriteManager_AddSprite(struct SpriteManager *manager, struct Sprite sprite);
int egSpriteManager_Qsorter(const void* a, const void* b);
void egSpriteManager_SortSprites(struct SpriteManager *manager);

#endif //SDL2_LEARNING_SPRITEMANAGER_H
