//
// Created by pedro on 15/02/2022.
//

#include "Resources.h"
#include "Game.h"

SDL_Texture *Resources::getImage(std::string file) {
    auto got = imageTable.find(file);
    if (got == imageTable.end()) {
        // Not found
        auto texture = IMG_LoadTexture(Game::getInstance().getRenderer(), file.c_str());
        if (texture != nullptr) {
            imageTable[file] = texture;
            return texture;
        } else {
            std::cout << SDL_GetError() << std::endl;
        }
    } else {
        return got->second;
    }
    return nullptr;
}

void Resources::clearImages() {
    for (auto image: imageTable) {
        free(image.second);
    }
    imageTable.clear();
}

Mix_Music *Resources::getMusic(std::string file) {
    auto got = musicTable.find(file);
    if (got == musicTable.end()) {
        // Not found
        auto *loadedMusic = Mix_LoadMUS(file.c_str());
        if (loadedMusic != nullptr) {
            musicTable[file] = loadedMusic;
            return loadedMusic;
        } else {
            std::cout << "Error ao importar música: " << SDL_GetError() << std::endl;
        }
    } else {
        return got->second;
    }
    return nullptr;
}

void Resources::clearMusics() {
    for (auto music: musicTable) {
        free(music.second);
    }
    musicTable.clear();

}

Mix_Chunk *Resources::getSound(std::string file) {
    auto got = soundTable.find(file);
    if (got == soundTable.end()) {
        // Not found
        Mix_Chunk *musicChunk = Mix_LoadWAV(file.c_str());
        if (musicChunk != nullptr) {
            soundTable[file] = musicChunk;
            return musicChunk;
        } else {
            std::cout << SDL_GetError() << std::endl;
        }
    } else {
        return got->second;
    }
    return nullptr;
}

void Resources::clearSounds() {
    for (auto sound: soundTable) {
        free(sound.second);
    }
    soundTable.clear();

}
