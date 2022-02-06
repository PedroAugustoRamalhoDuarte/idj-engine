#include "Face.h"

Face::Face(GameObject &associated) : Component(associated) {
    hitpoints = DEFAULT_HP;
}

void Face::damage(int damage) {
    hitpoints -= damage;
    if (hitpoints <= 0) {
        associated.requestDelete();
        // Play sound if exist
        auto sound = associated.getComponent("Sound");
        if (sound) {
            sound.associated.play()
        }
    }
}

void Face::update(float dt) {}

void Face::render() {}

bool Face::is(std::string type) {
    return type == "Face";
}

