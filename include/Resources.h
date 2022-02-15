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
    static std::unordered_map<std::string, SDL_Texture *> imageTable;
    static std::unordered_map<std::string, Mix_Music *> musicTable;
    static std::unordered_map<std::string, Mix_Chunk *> soundTable;

public:
    static SDL_Texture *getImage(std::string file);

    static void clearImages();

    static Mix_Music *getMusic(std::string file);

    static void clearMusics();

    static Mix_Chunk *getSound(std::string file);

    static void clearSounds();
};


#endif //IDJ_ENGINE_RESOURCES_H
