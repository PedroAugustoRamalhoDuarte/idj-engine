//
// Created by pedro on 31/01/2022.
//

#ifndef IDJ_ENGINE_MUSIC_H
#define IDJ_ENGINE_MUSIC_H

#define INCLUDE_SDL
#define INCLUDE_SDL_MIXER

#include "../lib/SDL_include.h"
#include "iostream"

class Music {
private:
    Mix_Music *music;

public:
    Music();

    Music(std::string file);

    ~Music();

    void play(int times = -1);

    void stop(int msTopStop = 1500);

    void open(std::string file);

    bool isOpen();

};


#endif //IDJ_ENGINE_MUSIC_H
