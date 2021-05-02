//
// Created by eevee on 02.05.21.
//

#ifndef SDL2_LEARNING_SPRITELIST_H
#define SDL2_LEARNING_SPRITELIST_H

#include "Sprite.h"

typedef struct SpriteList {
    struct Sprite *array;
    size_t size;
} egSpriteList_t;

void egSpriteList_Init(egSpriteList_t *list);
unsigned long egSpriteList_Insert(egSpriteList_t *list, struct Sprite item);
void egSpriteList_Remove(egSpriteList_t *list, int index);
void egSpriteList_Free(egSpriteList_t *list);

#endif //SDL2_LEARNING_SPRITELIST_H
