//
// Created by pedro on 21/02/2022.
//

#ifndef IDJ_ENGINE_INPUTMANAGER_H
#define IDJ_ENGINE_INPUTMANAGER_H

#define INCLUDE_SDL

#include "../lib/SDL_include.h"

#define LEFT_ARROW_KEY    SDLK_LEFT
#define RIGHT_ARROW_KEY   SDLK_RIGHT
#define UP_ARROW_KEY      SDLK_UP
#define DOWN_ARROW_KEY    SDLK_DOWN
#define ESCAPE_KEY        SDLK_ESCAPE
#define LEFT_MOUSE_BUTTON SDL_BUTTON_LEFT

class InputManager {
private:
    // Down = true, Up = false
    bool mouseState[6] = {false};
    int mouseUpdate[6] = {0};

    bool keyState[416] = {false};
    int keyUpdate[416] = {0};

    bool quitRequested = false;
    int updateCounter = 0;

    int mouseX = 0;
    int mouseY = 0;

public:
    void update();

    bool keyPress(int);

    bool keyRelease(int);

    bool isKeyDown(int);

    bool mousePress(int);

    bool mouseRelease(int);

    bool isMouseDown(int);

    bool isQuitRequested() const;

    int getMouseX() const;

    int getMouseY() const;

    static InputManager &getInstance();

    InputManager();

    ~InputManager();
};


#endif //IDJ_ENGINE_INPUTMANAGER_H
