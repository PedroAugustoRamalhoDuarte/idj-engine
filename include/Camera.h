//
// Created by pedro on 21/02/2022.
//

#ifndef IDJ_ENGINE_CAMERA_H
#define IDJ_ENGINE_CAMERA_H


#include "GameObject.h"
#include "Vec2.h"

class Camera {
private:
    static GameObject *focus;
public:
    static Vec2 pos;
    static Vec2 speed;

    static void follow(GameObject *newFocus);

    static void unFollow();

    static void update(float dt);
};


#endif //IDJ_ENGINE_CAMERA_H
