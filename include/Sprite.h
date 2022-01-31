#ifndef IDJ_ENGINE_SPRITE_H
#define IDJ_ENGINE_SPRITE_H

#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE

#include "../lib/SDL_include.h"
#include <iostream>
// #include "Game.h"

class Sprite {
private:
    SDL_Texture *texture;
    int width;
    int height;
    SDL_Rect clipRect;
public:
    Sprite();

    Sprite(std::string file);

    ~Sprite();

    void open(std::string file);

    void setClip(int x, int y, int w, int h);

    void render(int x, int y);

    int getWidth();

    int getHeight();

    bool isOpen();
};


#endif //IDJ_ENGINE_SPRITE_H
