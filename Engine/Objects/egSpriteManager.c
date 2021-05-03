//
// Created by eevee on 02.05.21.
//

#include "egSpriteManager.h"
#include "egSpriteList.h"

void egSpriteManager_Draw(struct egSpriteManager *manager, struct egSDLContext *context) {
    for(int i = 0; i != manager->spriteList->size - 1; i++){
        Sprite_Draw(&manager->spriteList->list[i], context);
    }
}

void egSpriteManager_AddSprite(struct egSpriteManager *manager, struct egSprite sprite) {
    egSpriteList_Insert(manager->spriteList, sprite);
}

int egSpriteManager_DrawDepthSorter(const void *a, const void *b) {
    struct egSprite sprite1 = *((struct egSprite*)a);
    struct egSprite sprite2 = *((struct egSprite*)a);
    
    double double_a = sprite1.drawDepth;
    double double_b = sprite2.drawDepth;
    
    if (double_a == double_b ) return 0;
    else if (double_a < double_b ) return -1;
    else return 1;
}

void egSpriteManager_SortSprites(struct egSpriteManager *manager) {
    qsort(manager->spriteList->list, manager->spriteList->size - 1, sizeof(struct egSprite),
          egSpriteManager_DrawDepthSorter);
}
