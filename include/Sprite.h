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
    Sprite(GameObject &associated);

    Sprite(GameObject &associated, std::string file);

    ~Sprite();

    void open(std::string file);

    void setClip(int x, int y, int w, int h);

    void render() override;

    int getWidth();

    int getHeight();

    bool isOpen();

    void update(float dt) override;

    bool is(std::string type) override;
};


#endif //IDJ_ENGINE_SPRITE_H
