//
// Created by pedro on 21/02/2022.
//

#include "InputManager.h"

bool InputManager::isQuitRequested() const {
    return quitRequested;
}

int InputManager::getMouseX() const {
    return mouseX;
}

int InputManager::getMouseY() const {
    return mouseY;
}

InputManager &InputManager::getInstance() {
    static InputManager inputManager = InputManager();
    return inputManager;
}

InputManager::InputManager() {
    quitRequested = false;
    updateCounter = 0;
    mouseX = 0;
    mouseY = 0;
}

int keycodeToInt(int sdlKeyCode) {
    if (sdlKeyCode > 0x40000000) {
        return sdlKeyCode - 0x3FFFFF81;
    } else {
        return sdlKeyCode;
    }
}

void InputManager::update() {
    SDL_Event *event;
    SDL_PollEvent(event);

    SDL_GetMouseState(&mouseX, &mouseY);
    quitRequested = false;

    if (!event->key.repeat) {
        switch (event->type) {
            case SDL_KEYDOWN:
                keyState[keycodeToInt(event->key.keysym.sym)] = true;
                keyUpdate[keycodeToInt(event->key.keysym.sym)] += 1;
                break;
            case SDL_KEYUP:
                keyState[keycodeToInt(event->key.keysym.sym)] = false;
                keyUpdate[keycodeToInt(event->key.keysym.sym)] += 1;
                break;
            case SDL_MOUSEBUTTONDOWN:
                mouseState[event->button.button] = true;
                mouseUpdate[event->button.button] += 1;
                break;
            case SDL_MOUSEBUTTONUP:
                mouseState[event->button.button] = false;
                mouseUpdate[event->button.button] += 1;
                break;
            case SDL_QUIT:
                quitRequested = true;

        }
    }
}

bool InputManager::keyPress(int key) {
    return keyState[keycodeToInt(key)];
}

bool InputManager::keyRelease(int key) {
    return !keyState[keycodeToInt(key)];
}

bool InputManager::isKeyDown(int key) {
    return keyUpdate[keycodeToInt(key)];
}

bool InputManager::mousePress(int mouse) {
    return mouseState[mouse];
}

bool InputManager::mouseRelease(int mouse) {
    return !mouseState[mouse];
}

bool InputManager::isMouseDown(int mouse) {
    return mouseUpdate[mouse];
}
