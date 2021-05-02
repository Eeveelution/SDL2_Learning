//
// Created by eevee on 02.05.21.
//

#ifndef SDL2_LEARNING_SPRITELIST_H
#define SDL2_LEARNING_SPRITELIST_H

#include "Sprite.h"

struct SpriteList {
    struct Sprite *list;
    size_t size;
};

void egSpriteList_Init(struct SpriteList *list);
unsigned long egSpriteList_Insert(struct SpriteList *list, struct Sprite item);
void egSpriteList_Remove(struct SpriteList *list, int index);
void egSpriteList_Free(struct SpriteList *list);

#endif //SDL2_LEARNING_SPRITELIST_H
