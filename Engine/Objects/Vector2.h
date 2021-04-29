//
// Created by eevee on 28.04.21.
//

#ifndef SDL2_LEARNING_VECTOR2_H
#define SDL2_LEARNING_VECTOR2_H

#include <SDL.h>

struct Vector2 {
    int x, y;
};

SDL_Point* Vector2_ToPoint(struct Vector2 *srcPoint);

#endif //SDL2_LEARNING_VECTOR2_H
