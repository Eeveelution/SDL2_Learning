//
// Created by eevee on 02.05.21.
//

#ifndef SDL2_LEARNING_EGSPRITELIST_H
#define SDL2_LEARNING_EGSPRITELIST_H

#include "egSprite.h"

struct egSpriteList {
    struct egSprite *list;
    size_t size;
};

void egSpriteList_Init(struct egSpriteList *list);
unsigned long egSpriteList_Insert(struct egSpriteList *list, struct egSprite item);
void egSpriteList_Remove(struct egSpriteList *list, int index);
void egSpriteList_Free(struct egSpriteList *list);

#endif //SDL2_LEARNING_EGSPRITELIST_H
