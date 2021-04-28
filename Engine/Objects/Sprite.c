//
// Created by eevee on 28.04.21.
//

#include "Sprite.h"

struct Sprite *Sprite_NewSpriteEmpty() {
    struct Sprite *sprite = malloc(sizeof(struct Sprite));
    
    sprite->spriteTexture = NULL;
    sprite->spriteWidth = 0;
    sprite->spriteHeight = 0;
    
    return sprite;
}

