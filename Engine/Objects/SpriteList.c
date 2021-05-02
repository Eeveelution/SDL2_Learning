//
// Created by eevee on 02.05.21.
//

#include "SpriteList.h"

void egSpriteList_Init(egSpriteList_t *list) {
    struct Sprite *sprite_pointer;
    
    sprite_pointer = malloc(sizeof(struct Sprite));
    
    if (sprite_pointer == NULL)
    {
        printf("Unable to allocate memory, exiting.\n");
        free(sprite_pointer);
        exit(0);
    }
    else
    {
        list->array = sprite_pointer;
        list->size = 0;
    }
}

unsigned long egSpriteList_Insert(egSpriteList_t *list, struct Sprite item) {
    struct Sprite *sprite_pointer;
    
    list->size += 1;
    
    sprite_pointer = realloc(list->array, list->size * sizeof(struct Sprite));
    
    if (sprite_pointer == NULL)
    {
        printf("Unable to reallocate memory, exiting.\n");
        free(sprite_pointer);
        exit(0);
    }
    else
    {
        list->array = sprite_pointer;
        list->array[list->size-1] = item;
        
        return list->size-1;
    }
}

void egSpriteList_Remove(egSpriteList_t *list, int index) {
    int i;
    
    egSpriteList_t temp;
    
    struct Sprite *sprite_pointer;
    
    egSpriteList_Init(&temp);
    
    for(i=index; i < list->size; i++)
    {
        list->array[i] = list->array[i + 1];
    }
    
    list->size -= 1;
    
    for (i = 0; i < list->size; i++)
    {
        egSpriteList_Insert(&temp, list->array[i]);
    }
    
    sprite_pointer = realloc(temp.array, temp.size * sizeof(struct Sprite));
    
    if (sprite_pointer == NULL)
    {
        printf("Unable to reallocate memory, exiting.\n");
        free(sprite_pointer);
        exit(0);
    }
    else
    {
        list->array = sprite_pointer;
    }
}

void egSpriteList_Free(egSpriteList_t *list) {
    free(list->array);
    list->array = NULL;
    list->size = 0;
}

