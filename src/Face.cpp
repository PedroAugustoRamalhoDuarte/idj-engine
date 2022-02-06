#include "Face.h"
#include "Sound.h"

Face::Face(GameObject &associated) : Component(associated) {
    this->hitpoints = 30;
}

void Face::damage(int damage) {
    hitpoints = hitpoints - damage;
    if (hitpoints <= 0) {
        associated.requestDelete();
        // Play sound if exist
        Component *soundComponent = associated.getComponent("Sound");
        if (soundComponent) {
            auto *sound = dynamic_cast<Sound *>(soundComponent);
            sound->play(1);
        }
    }
}

void Face::update(float dt) {}

void Face::render() {}

bool Face::is(std::string type) {
    return type == "Face";
}

int Face::getHitpoints() const {
    return hitpoints;
}

