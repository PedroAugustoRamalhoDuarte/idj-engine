#include "../include/Rect.h"
#include "iostream"

bool Rect::contains(float mouseX, float mouseY) {
    if (mouseX > x and mouseX < x + w and mouseY > y and mouseY < y + h) {
        return true;
    } else {
        return false;
    }
}
