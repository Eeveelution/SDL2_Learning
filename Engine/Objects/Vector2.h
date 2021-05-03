//
// Created by eevee on 28.04.21.
//

#ifndef SDL2_LEARNING_VECTOR2_H
#define SDL2_LEARNING_VECTOR2_H

#include <SDL.h>

#include <stdbool.h>

struct Vector2 {
    int x, y;
};

SDL_Point* Vector2_ToPoint(struct Vector2 *srcPoint);

bool Vector2_Contains(int x1, int x2, int y1, int y2, int pointX, int pointY);

#endif //SDL2_LEARNING_VECTOR2_H
