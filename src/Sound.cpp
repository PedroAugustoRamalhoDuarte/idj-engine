#include "../include/Sound.h"

Sound::Sound(GameObject &associated) : Component(associated) {
    chunk = nullptr;
}

Sound::Sound(GameObject &associated, std::string file) : Sound(associated) {
    open(file);
}

Sound::~Sound() {
//    if (chunk) {
//        Mix_FreeChunk(chunk);
//    }
}

void Sound::play(int times) {
    channel = Mix_PlayChannel(-1, chunk, times - 1);
}

void Sound::stop() {
    if (chunk) {
        Mix_HaltChannel(channel);
    }
}

void Sound::open(std::string file) {
    // TODO: Handle error
    Mix_Chunk *musicChunk = Mix_LoadWAV(file.c_str());
    if (musicChunk != nullptr) {
        chunk = musicChunk;
    } else {
        std::cout << "Error ao importar música" << std::endl;
    }
}

bool Sound::isOpen() {
    return false;
}


void Sound::update(float dt) {
}

void Sound::render() {
}

bool Sound::is(std::string type) {
    return true;
}

