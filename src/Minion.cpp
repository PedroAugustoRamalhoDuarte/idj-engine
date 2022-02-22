//
// Created by pedro on 22/02/2022.
//

#include "Minion.h"
#include "Sprite.h"
#include "Assets.h"

void Minion::update(float dt) {
    // Update rotation
    Vec2 offset(100, 0);
    Vec2 rotated = offset.rotate(arc);

    associated.box.x = rotated.x + alienCenter->box.x;
    associated.box.y = rotated.y + alienCenter->box.y;
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
    associated.addComponent(sprite);

    // Position for minion
//    Vec2 offset(50, 0);
//    if (this->alienCenter) {
//        Vec2 initialPosition = offset + this->alienCenter->box.middle();
//        associated.box.x = initialPosition.x;
//        associated.box.y = initialPosition.y;
//    }


}
