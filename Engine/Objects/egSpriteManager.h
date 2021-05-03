//
// Created by eevee on 02.05.21.
//

#ifndef SDL2_LEARNING_EGSPRITEMANAGER_H
#define SDL2_LEARNING_EGSPRITEMANAGER_H

#include "../egSDLContext.h"
#include "egSprite.h"

struct egSpriteManager {
    struct egSpriteList *spriteList;
    struct egSpriteList *clickableSpriteList;
    struct egSpriteList *hoverableSpriteList;
};

void egSpriteManager_Draw(struct egSpriteManager *manager, struct egSDLContext *context);

void egSpriteManager_AddSprite(struct egSpriteManager *manager, struct egSprite sprite);
int egSpriteManager_DrawDepthSorter(const void* a, const void* b);
void egSpriteManager_SortSprites(struct egSpriteManager *manager);

void egSpriteManager_MouseHoverEvent(struct egSpriteManager *manager, struct Vector2 mousePoint);
void egSpriteManager_MouseDownEvent(struct egSpriteManager *manager, struct Vector2 mousePoint);

#endif //SDL2_LEARNING_EGSPRITEMANAGER_H
