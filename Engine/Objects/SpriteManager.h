//
// Created by eevee on 02.05.21.
//

#ifndef SDL2_LEARNING_SPRITEMANAGER_H
#define SDL2_LEARNING_SPRITEMANAGER_H

#include "../EngineInclude.h"
#include "SpriteList.h"

struct SpriteManager {
    struct SpriteList spriteList;
};

void egSpriteManager_Draw(struct SpriteManager *manager, struct SDLContext *context);

#endif //SDL2_LEARNING_SPRITEMANAGER_H
