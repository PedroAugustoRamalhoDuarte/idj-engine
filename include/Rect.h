//
// Created by pedro on 06/02/2022.
//

#ifndef IDJ_ENGINE_RECT_H
#define IDJ_ENGINE_RECT_H

#include "Vec2.h"

class Rect {
public:
    float x, y, w, h;

    bool contains(float x, float y);

    Vec2 middle();
};

#endif //IDJ_ENGINE_RECT_H
