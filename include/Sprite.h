#ifndef IDJ_ENGINE_SPRITE_H
#define IDJ_ENGINE_SPRITE_H

#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE

#include "../lib/SDL_include.h"
#include "Component.h"
#include <iostream>

class Sprite : public Component {
private:
    SDL_Texture *texture;
    int width;
    int height;
    SDL_Rect clipRect;
    Vec2 scale;
public:
    float angleDeg;

    explicit Sprite(GameObject &associated);

    Sprite(GameObject &associated, std::string file);

    ~Sprite();

    void start() override;

    void open(std::string file);

    void setClip(int x, int y, int w, int h);

    void setScaleX(float scaleX, float scaleY);

    Vec2 getScale();

    void render() override;

    void render(int x, int y);

    int getWidth();

    int getHeight();

    bool isOpen();

    void update(float dt) override;

    bool is(std::string type) override;
};


#endif //IDJ_ENGINE_SPRITE_H
