//
// Created by pedro on 22/02/2022.
//

#include "Minion.h"
#include "Sprite.h"
#include "Assets.h"
#include "Bullet.h"
#include "Game.h"

void Minion::update(float dt) {
    // Default offset
    Vec2 offset(125, 0);
    Vec2 rotated = offset.rotate(arc);

    // Rotate minion based on center
    Vec2 alienMiddle = alienCenter->box.middle();
    associated.box.x = (rotated.x + alienMiddle.x) - associated.box.h / 2;
    associated.box.y = (rotated.y + alienMiddle.y) - associated.box.w / 2;

    // Update angle
    arc += MINION_VEL;
}

void Minion::render() {

}

void Minion::start() {

}

bool Minion::is(std::string type) {
    return "Minion";
}

Minion::Minion(GameObject &associated, GameObject *alienCenter, float arcOffSetDeg) : Component(
        associated) {
    // Initialize others attributes
    // auto alienCenterPtr = alienCenter;
    this->alienCenter = alienCenter;
    arc = arcOffSetDeg;

    // Sprite for minion
    auto sprite = new Sprite(associated, Assets::getImg("minion.png"));
    float scale = ((rand() % 30) / 60.0) + 1;
    std::cout << scale << std::endl;
    sprite->setScaleX(scale, scale);
    associated.addComponent(sprite);
}

void Minion::shoot(Vec2 target) {
    auto center = Vec2(associated.box.x, associated.box.y);
    float angle = center.angle(target);

    // New bullet Game Object
    auto bulletGo = new GameObject();
    bulletGo->box.x = center.x;
    bulletGo->box.y = center.y;
    auto bullet = new Bullet(*bulletGo, angle, 0.01, 5, 1000, "minionbullet1.png");
    bulletGo->addComponent(bullet);
    Game::getInstance().getState().addObject(bulletGo);
}
