//
// Created by eevee on 29.04.21.
//
#include "Vector2.h"

SDL_Point* Vector2_ToPoint(struct Vector2 *srcPoint) {
    SDL_Point* point = malloc(sizeof(SDL_Point));

    point->x = srcPoint->x;
    point->y = srcPoint->y;

    return point;
}

bool Vector2_Contains(int x1, int y1, int x2, int y2, int pointX, int pointY) {
    if (pointX > x1 && pointX < x2 &&
        pointY > y1 && pointY < y2)
        return true;
    
    return false;
}
