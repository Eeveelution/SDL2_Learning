//
// Created by eevee on 02.05.21.
//

#include "egSpriteList.h"

void egSpriteList_Init(struct egSpriteList *list) {
    struct egSprite *sprite_pointer;
    
    sprite_pointer = malloc(sizeof(struct egSprite));
    
    if (sprite_pointer == NULL)
    {
        printf("Unable to allocate memory, exiting.\n");
        free(sprite_pointer);
        exit(0);
    }
    else
    {
        list->list = sprite_pointer;
        list->size = 0;
    }
}

unsigned long egSpriteList_Insert(struct egSpriteList *list, struct egSprite item) {
    struct egSprite *sprite_pointer;
    
    list->size += 1;
    
    sprite_pointer = realloc(list->list, list->size * sizeof(struct egSprite));
    
    if (sprite_pointer == NULL)
    {
        printf("Unable to reallocate memory, exiting.\n");
        free(sprite_pointer);
        exit(0);
    }
    else
    {
        list->list = sprite_pointer;
        list->list[list->size - 1] = item;
        
        return list->size-1;
    }
}

void egSpriteList_Remove(struct egSpriteList *list, int index) {
    int i;
    
    struct egSpriteList temp;
    
    struct egSprite *sprite_pointer;
    
    egSpriteList_Init(&temp);
    
    for(i=index; i < list->size; i++)
    {
        list->list[i] = list->list[i + 1];
    }
    
    list->size -= 1;
    
    for (i = 0; i < list->size; i++)
    {
        egSpriteList_Insert(&temp, list->list[i]);
    }
    
    sprite_pointer = realloc(temp.list, temp.size * sizeof(struct egSprite));
    
    if (sprite_pointer == NULL)
    {
        printf("Unable to reallocate memory, exiting.\n");
        free(sprite_pointer);
        exit(0);
    }
    else
    {
        list->list = sprite_pointer;
    }
}

void egSpriteList_Free(struct egSpriteList *list) {
    free(list->list);
    list->list = NULL;
    list->size = 0;
}

