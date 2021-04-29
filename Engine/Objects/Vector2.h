//
// Created by eevee on 28.04.21.
//

#ifndef SDL2_LEARNING_VECTOR2_H
#define SDL2_LEARNING_VECTOR2_H

struct Vector2 {
    int x, y;
};

SDL_Point* Vector2_ToPoint(struct Vector2 *srcPoint) {
    SDL_Point* point = malloc(sizeof(SDL_Point));
    
    point->x = srcPoint->x;
    point->y = srcPoint->y;
    
    return point;
}

#endif //SDL2_LEARNING_VECTOR2_H
