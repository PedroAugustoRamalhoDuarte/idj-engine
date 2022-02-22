#include <algorithm>
#include "../include/GameObject.h"

GameObject::GameObject() {
    isDead = false;
    started = false;
}

GameObject::~GameObject() {
    components.clear();
}

void GameObject::update(float dt) {
    for (auto &cpt: components) {
        cpt->update(dt);
    }
}

void GameObject::render() {
    for (auto &cpt: components) {
        cpt->render();
    }
}

bool GameObject::getIsDead() {
    return isDead;
}

void GameObject::requestDelete() {
    isDead = true;
}

void GameObject::addComponent(Component *cpt) {
    components.emplace_back(cpt);

    if (started) {
        cpt->start();
    }
}

// TODO: Build this function
void GameObject::removeComponent(Component *cpt) {
    // std::remove_if(components.begin(), components.end(), [&](Component *a) { return *a == *cpt; });
}

Component *GameObject::getComponent(std::string type) {
    Component *temp = nullptr;
    for (auto &cpt: components) {
        if (cpt->is(type)) {
            temp = cpt.get();
            // Why breaks bug the function
        }
    }
    return temp;
}

void GameObject::start() {
    started = true;

    for (auto &cpt: components) {
        cpt->start();
    }
}
