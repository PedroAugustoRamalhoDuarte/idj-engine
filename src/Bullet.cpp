//
// Created by pedro on 22/02/2022.
//

#include "Bullet.h"
#include "Sprite.h"
#include "Assets.h"

void Bullet::update(float dt) {
    associated.box.x += dt * speed.x;
    associated.box.y += dt * speed.y;
    distanceLeft -= dt * speed.magnitude();

    if (distanceLeft <= 0) {
        associated.requestDelete();
    }
}

void Bullet::render() {

}

void Bullet::start() {

}

bool Bullet::is(std::string type) {
    return type == "Bullet";
}

int Bullet::getDamage() const {
    return damage;
}

Bullet::Bullet(GameObject &associated, float angle, float speed, int damage, float maxDistance, std::string sprite)
        : Component(associated) {
    this->speed = Vec2(speed * cos(angle), speed * sin(angle));
    this->distanceLeft = maxDistance;
    this->damage = damage;
    auto s = new Sprite(associated, Assets::getImg(sprite));
    associated.addComponent(s);
}

