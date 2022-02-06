//
// Created by pedro on 06/02/2022.
//

#include "../include/Vec2.h"

Vec2::Vec2(float x, float y) : x(x), y(y) {}

Vec2::Vec2() {
    x = 0;
    y = 0;
}

Vec2 Vec2::operator+(const Vec2 &obj) const {
    Vec2 vec2{};
    vec2.x = x + obj.x;
    vec2.y = y + obj.y;
    return vec2;
}

Vec2 Vec2::rotate(float angle) {
    Vec2 vec2{};
    vec2.x = x * std::cos(angle) - y * std::sin(angle);
    vec2.y = y * std::cos(angle) + x * std::sin(angle);
    return vec2;
}




