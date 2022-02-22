//
// Created by pedro on 21/02/2022.
//

#include "Camera.h"
#include "InputManager.h"

// Initialize Camera static

Vec2 Camera::pos = Vec2();
Vec2 Camera::speed = Vec2();
GameObject *Camera::focus = nullptr;

void Camera::follow(GameObject *newFocus) {
    focus = newFocus;
}

void Camera::unFollow() {
    focus = nullptr;
}

void Camera::update(float dt) {
    if (focus) {
        // TODO: Later
    } else {
        auto inputManager = InputManager::getInstance();

        // speed = dt;
        if (inputManager.keyPress(LEFT_ARROW_KEY)) {
            pos.x -= 20;
        } else if (inputManager.keyPress(RIGHT_ARROW_KEY)) {
            pos.x += 20;
        }
        // else if (inputManager.keyPress(LEFT_ARROW_KEY)) {
//
//        } else if (inputManager.keyPress(LEFT_ARROW_KEY)) {
//
//        }
    }

}
