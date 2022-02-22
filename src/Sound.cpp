#include "../include/Sound.h"
#include "Resources.h"

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
    chunk = Resources::getSound(file);
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

void Sound::start() {

}

