//
// Created by eevee on 02.05.21.
//

#include "egSpriteManager.h"
#include "egSpriteList.h"


struct egSpriteManager *egSpriteManager_CreateNew () {
    struct egSpriteManager *manager = malloc(sizeof(struct egSpriteManager));
    
    manager->spriteList = malloc(sizeof(struct egSpriteList));
    manager->hoverableSpriteList = malloc(sizeof(struct egSpriteList));
    manager->clickableSpriteList = malloc(sizeof(struct egSpriteList));
    
    egSpriteList_Init(manager->spriteList);
    egSpriteList_Init(manager->hoverableSpriteList);
    egSpriteList_Init(manager->clickableSpriteList);
    
    return manager;
}

void egSpriteManager_Draw(struct egSpriteManager *manager, struct egSDLContext *context) {
    //Sort them by Draw Depth first
    egSpriteManager_SortSprites(manager);
    
    for(int i = 0; i != manager->spriteList->size - 1; i++){
        egSprite_Draw(&manager->spriteList->list[i], context);
    }
}

void egSpriteManager_AddSprite(struct egSpriteManager *manager, struct egSprite sprite) {
    //Adding to Clickable list, this is to search for Clickable Sprites faster
    if(sprite.handlesMouseDown) {
        egSpriteList_Insert(manager->clickableSpriteList, sprite);
    }
    //Add to Hoverable list, this speeds up searching for Hoverable Sprites faster
    if(sprite.handlesMouseOver) {
        egSpriteList_Insert(manager->hoverableSpriteList, sprite);
    }
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
    qsort(manager->spriteList->list, manager->spriteList->size - 1, sizeof(struct egSprite), egSpriteManager_DrawDepthSorter);
}

void egSpriteManager_MouseHoverEvent(struct egSpriteManager *manager, struct Vector2 mousePoint) {
    //Loop over Hoverable Sprites and trigger Hover event
    for(int i = 0; i != manager->hoverableSpriteList->size - 1; i++){
        struct egSprite *sprite = &manager->hoverableSpriteList->list[i];
        //Top Left Corner
        int topX = sprite->spriteLocation.x,
            topY = sprite->spriteLocation.y;
        //Bottom Right Corner
        int bottomX = sprite->spriteLocation.x + sprite->spriteSize.x,
            bottomY = sprite->spriteLocation.y + sprite->spriteSize.y;
        //Check if Point Exists
        if(Vector2_Contains(topX, topY, bottomX, bottomY, mousePoint.x, mousePoint.y))
            if(sprite->OnMouseHover != NULL)
                sprite->OnMouseHover(mousePoint);
    }
}

void egSpriteManager_MouseDownEvent(struct egSpriteManager *manager, struct Vector2 mousePoint) {
    //Loop over Clickable Sprites and trigger a Click event
    for(int i = 0; i != manager->hoverableSpriteList->size - 1; i++){
        struct egSprite *sprite = &manager->clickableSpriteList->list[i];
        //Top Left Corner
        int topX = sprite->spriteLocation.x,
                topY = sprite->spriteLocation.y;
        //Bottom Right Corner
        int bottomX = sprite->spriteLocation.x + sprite->spriteSize.x,
                bottomY = sprite->spriteLocation.y + sprite->spriteSize.y;
        //Check if Point Exists
        if(Vector2_Contains(topX, topY, bottomX, bottomY, mousePoint.x, mousePoint.y))
            if(sprite->OnMouseDown != NULL)
                sprite->OnMouseDown(mousePoint);
    }
}

void egSprtieManager_Free(struct egSpriteManager *manager) {
    egSpriteList_Free(manager->spriteList);
    egSpriteList_Free(manager->hoverableSpriteList);
    egSpriteList_Free(manager->clickableSpriteList);
    
    free(manager);
}
