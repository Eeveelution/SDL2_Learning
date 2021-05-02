//
// Created by eevee on 02.05.21.
//

#include "SpriteManager.h"
#include "SpriteList.h"

void egSpriteManager_Draw(struct SpriteManager *manager, struct SDLContext *context) {
    for(int i = 0; i != manager->spriteList->size - 1; i++){
        Sprite_Draw(&manager->spriteList->list[i], context);
    }
}

void egSpriteManager_AddSprite(struct SpriteManager *manager, struct Sprite sprite) {
    egSpriteList_Insert(manager->spriteList, sprite);
}

int egSpriteManager_Qsorter(const void *a, const void *b) {
    struct Sprite sprite1 = *((struct Sprite*)a);
    struct Sprite sprite2 = *((struct Sprite*)a);
    
    double double_a = sprite1.drawDepth;
    double double_b = sprite2.drawDepth;
    
    if (double_a == double_b ) return 0;
    else if (double_a < double_b ) return -1;
    else return 1;
}

void egSpriteManager_SortSprites(struct SpriteManager *manager) {
    qsort(manager->spriteList->list, manager->spriteList->size - 1, sizeof(struct Sprite), egSpriteManager_Qsorter);
}
