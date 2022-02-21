//
// Created by pedro on 21/02/2022.
//

#include <iostream>
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

InputManager::InputManager() {
    quitRequested = false;
    updateCounter = 0;
    mouseX = 0;
    mouseY = 0;
}


InputManager &InputManager::getInstance() {
    static InputManager inputManager;
    return inputManager;
}


int keycodeToInt(int sdlKeyCode) {
    if (sdlKeyCode > 0x40000000) {
        return sdlKeyCode - 0x3FFFFF81;
    } else {
        return sdlKeyCode;
    }
}

void InputManager::update() {
    SDL_Event event;
    updateCounter++;
    SDL_GetMouseState(&mouseX, &mouseY);
    quitRequested = false;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_KEYDOWN:
                if (event.key.repeat) {
                    break;
                }
                std::cout << "KeyDown" << event.type << std::endl;
                keyState[keycodeToInt(event.key.keysym.sym)] = true;
                keyUpdate[keycodeToInt(event.key.keysym.sym)] = updateCounter;
                break;
            case SDL_KEYUP:
                keyState[keycodeToInt(event.key.keysym.sym)] = false;
                keyUpdate[keycodeToInt(event.key.keysym.sym)] = updateCounter;
                break;
            case SDL_MOUSEBUTTONDOWN:
                std::cout << "MOUSEBUTTONDOWN" << event.type << std::endl;
                mouseState[event.button.button] = true;
                mouseUpdate[event.button.button] = updateCounter;
                break;
            case SDL_MOUSEBUTTONUP:
                mouseState[event.button.button] = false;
                mouseUpdate[event.button.button] = updateCounter;
                break;
            case SDL_QUIT:
                quitRequested = true;

        }
    }


}

bool InputManager::keyPress(int key) {
    auto k = keycodeToInt(key);
    return (keyUpdate[k] == updateCounter && keyState[k]);
}

bool InputManager::keyRelease(int key) {
    auto k = keycodeToInt(key);
    return (keyUpdate[k] == updateCounter && !keyState[k]);
}

bool InputManager::isKeyDown(int key) {
    return keyState[keycodeToInt(key)];
}

bool InputManager::mousePress(int mouse) {
    return mouseUpdate[mouse] == updateCounter && mouseState[mouse];
}

bool InputManager::mouseRelease(int mouse) {
    return mouseUpdate[mouse] == updateCounter && !mouseState[mouse];
}

bool InputManager::isMouseDown(int mouse) {
    return mouseState[mouse];
}

InputManager::~InputManager() {

}
