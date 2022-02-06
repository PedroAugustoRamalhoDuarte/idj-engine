//
// Created by pedro on 06/02/2022.
//

#ifndef IDJ_ENGINE_RECT_H
#define IDJ_ENGINE_RECT_H

class Rect {
public:
    float x, y, w, h;

    bool contains(float x, float y);
};

#endif //IDJ_ENGINE_RECT_H
