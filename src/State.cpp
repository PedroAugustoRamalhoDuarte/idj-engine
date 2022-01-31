//
// Created by pedro on 31/01/2022.
//

#include "../include/State.h"

State::State() {
    quitRequested = false;
    bg = Sprite("../assets/img/cachorro-caramelo");
    music = Music("../assets/audio/stageState.ogg");
}

void State::loadAssets() {

}

void State::update(float dt) {
    if (SDL_QuitRequested()) {
        quitRequested = true;
    }
}

void State::render() {
    // Render background
    // bg.render(0, 0);
}

bool State::getQuitRequested() {
    return quitRequested;
}