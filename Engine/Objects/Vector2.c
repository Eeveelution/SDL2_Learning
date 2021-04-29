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
