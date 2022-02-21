#ifndef IDJ_ENGINE_GAME_H
#define IDJ_ENGINE_GAME_H

#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER

#include "../lib/SDL_include.h"
#include "State.h"
#include <iostream>
#include "InputManager.h"

class Game {
private:
    static Game *instance;
    SDL_Window *window{};
    SDL_Renderer *renderer{};
    State *state;

public:
    explicit Game(std::string title, int width, int height);

    ~Game();

    void run();

    SDL_Renderer *getRenderer();

    State &getState();

    static Game &getInstance();

};

#endif //IDJ_ENGINE_GAME_H
