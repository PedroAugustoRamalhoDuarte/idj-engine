#ifndef IDJ_ENGINE_SPRITE_H
#define IDJ_ENGINE_SPRITE_H

#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE

#include "../lib/SDL_include.h"
#include "Component.h"
#include <iostream>
// #include "Game.h"

// TODO: 2.1 A Sprite na verdade é um componente!

class Sprite : public Component {
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
