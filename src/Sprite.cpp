#include "../include/Sprite.h"

#include <utility>
#include "Game.h"
#include "Resources.h"
#include "Camera.h"

Sprite::Sprite(GameObject &associated) : Component(associated) {
    texture = nullptr;
}

Sprite::Sprite(GameObject &associated, std::string file) : Component(associated) {
    texture = nullptr;
    open(std::move(file));

    // Changes associated object
    associated.box.w = width;
    associated.box.h = height;
    setScaleX(1, 1);
}

Sprite::~Sprite() {
//    if (texture != nullptr) {
//        SDL_DestroyTexture(texture);
//        texture = nullptr;
//    }
}

void Sprite::open(std::string file) {
    // Handler already loaded texture
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }

    texture = Resources::getImage(file);

    if (SDL_QueryTexture(texture, nullptr, nullptr, &width, &height)) {
        std::cout << SDL_GetError() << std::endl;
    }

    setClip(0, 0, width, height);
}

void Sprite::setClip(int x, int y, int w, int h) {
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = w;
    clipRect.h = h;
}

void Sprite::render(int x, int y) {
    SDL_Rect dstrect = {.x = x, .y = y, .w = clipRect.w, .h = clipRect.h};
    if (SDL_RenderCopyEx(Game::getInstance().getRenderer(), texture, &clipRect, &dstrect, 0, nullptr, SDL_FLIP_NONE)) {
        std::cout << SDL_GetError() << std::endl;
    }
}


void Sprite::render() {
    render(static_cast<int>(associated.box.x) - Camera::pos.x, static_cast<int>(associated.box.y) - Camera::pos.y);
}

int Sprite::getHeight() {
    return height * scale.x;
}

int Sprite::getWidth() {
    return width * scale.y;
}

bool Sprite::isOpen() {
    return texture != nullptr;
}

void Sprite::update(float dt) {}


bool Sprite::is(std::string type) {
    return type == "Sprite";
}

void Sprite::start() {

}

void Sprite::setScaleX(float scaleX, float scaleY) {
    if (scaleX != 0 || scaleY != 0) {
        scale.x = scaleX;
        scale.y = scaleY;
    }
}

Vec2 Sprite::getScale() {
    return scale;
}

