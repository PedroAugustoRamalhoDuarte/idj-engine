//
// Created by pedro on 06/02/2022.
//

#ifndef IDJ_ENGINE_VEC2_H
#define IDJ_ENGINE_VEC2_H

#include <math.h>
#define PI 3.14159265

class Vec2 {
public:
    float x, y;

    Vec2(float x, float y);

    Vec2();

    Vec2 operator+(Vec2 const &obj) const;

    Vec2 rotate(float angle);

};


#endif //IDJ_ENGINE_VEC2_H
