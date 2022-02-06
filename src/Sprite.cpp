#include "../include/Sprite.h"

#include <utility>
#include "Game.h"

Sprite::Sprite(GameObject &associated) : Component(associated) {
    texture = nullptr;
}

Sprite::Sprite(GameObject &associated, std::string file) : Component(associated) {
    texture = nullptr;
    open(std::move(file));

    // Changes associated object
    associated.box.w = width;
    associated.box.h = height;
}

// TODO: Error with this destructor
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

    texture = IMG_LoadTexture(Game::getInstance().getRenderer(), file.c_str());
    if (texture == nullptr) {
        std::cout << SDL_GetError() << std::endl;
    }

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

void Sprite::render() {
    SDL_Rect dstrect = {.x = static_cast<int>(associated.box.x), .y = static_cast<int>(associated.box.y), .w = clipRect.w, .h = clipRect.h};
    if (SDL_RenderCopy(Game::getInstance().getRenderer(), texture, &clipRect, &dstrect)) {
        std::cout << SDL_GetError() << std::endl;
    }
}

int Sprite::getHeight() {
    return height;
}

int Sprite::getWidth() {
    return width;
}

bool Sprite::isOpen() {
    return texture != nullptr;
}

void Sprite::update(float dt) {}


bool Sprite::is(std::string type) {
    return type == "Sprite";
}

