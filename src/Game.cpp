#include "../include/Game.h"

Game *Game::instance = nullptr;

const static int DEFAULT_ALLOCATED_CHANNELS = 32;

Game::Game(std::string title, int width, int height) {
    if (instance != nullptr) throw "Game already initialize";

    instance = this;

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER)) {
        std::cout << SDL_GetError() << std::endl;
    }

    // TODO: handler error
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF);

    // Mix_Init();
    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
    Mix_AllocateChannels(DEFAULT_ALLOCATED_CHANNELS);

    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    state = new State();
}

Game &Game::getInstance() {
    if (instance != nullptr) {
        return *instance;
    } else {
        instance = new Game("teste", 10, 10);
    }
    return *instance;
}

Game::~Game() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    Mix_CloseAudio();
    Mix_Quit();

    IMG_Quit();

    SDL_Quit();
}

SDL_Renderer *Game::getRenderer() {
    return renderer;
}

void Game::run() {
    while (!state->getQuitRequested()) {
        state->update(33);
        state->render();
        SDL_RenderPresent(renderer);
        SDL_Delay(33);
    }
}

State &Game::getState() {
    return *state;
}

