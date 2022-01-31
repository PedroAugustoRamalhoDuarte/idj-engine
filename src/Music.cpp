//
// Created by pedro on 31/01/2022.
//

#include "../include/Music.h"

#include <utility>

Music::Music() {
    music = nullptr;
}

Music::Music(std::string file) {
    open(std::move(file));
}

void Music::play(int times) {
    if (music != nullptr) {
        if (Mix_PlayMusic(music, times)) {
            std::cout << SDL_GetError() << std::endl;
        }
    }
}


void Music::stop(int msToStop) {
    Mix_FadeOutMusic(msToStop);
}

void Music::open(std::string file) {
    Mix_Music *loadedMusic = Mix_LoadMUS(file.c_str());
    if (loadedMusic != nullptr) {
        music = loadedMusic;
    } else {
        std::cout << "Error ao importar música" << std::endl;
    }
}

bool Music::isOpen() {
    return music != nullptr;
}

// TODO: Error with this destructor
Music::~Music() {
//    if (isOpen()) {
//        Mix_FreeMusic(music);
//    }
}

