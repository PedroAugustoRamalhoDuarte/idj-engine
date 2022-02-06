#include "Face.h"
#include "Sound.h"

Face::Face(GameObject &associated) : Component(associated) {
    hitpoints = DEFAULT_HP;
}

void Face::damage(int damage) {
    hitpoints -= damage;
    if (hitpoints <= 0) {
        associated.requestDelete();
        // Play sound if exist
        Component* soundComponent = associated.getComponent("Sound");
        if (soundComponent) {
            auto* sound = dynamic_cast<Sound *>(soundComponent);
            sound->play();
        }
    }
}

void Face::update(float dt) {}

void Face::render() {}

bool Face::is(std::string type) {
    return type == "Face";
}

