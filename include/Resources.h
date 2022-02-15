//
// Created by pedro on 15/02/2022.
//

#ifndef IDJ_ENGINE_RESOURCES_H
#define IDJ_ENGINE_RESOURCES_H


#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER

#include "../lib/SDL_include.h"
#include <unordered_map>
#include <string>

class Resources {
private:
    std::unordered_map<std::string, SDL_Texture *> imageTable;
    std::unordered_map<std::string, Mix_Music *> musicTable;
    std::unordered_map<std::string, Mix_Chunk *> soundTable;

public:
    SDL_Texture *getImage(std::string file);

    void clearImages();

    Mix_Music *getMusic(std::string file);

    void clearMusics();

    Mix_Chunk *getSound(std::string file);

    void clearSounds();
};


#endif //IDJ_ENGINE_RESOURCES_H
