#include <algorithm>
#include "../include/GameObject.h"

GameObject::GameObject() {
    isDead = false;
}

GameObject::~GameObject() {
    for (auto &cpt: components) {
        // delete (cpt.get());
    }
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
    // std::unique_ptr<Component> temp(cpt);
    // components.push_back(temp);
}

// TODO: Build this function
void GameObject::removeComponent(Component *cpt) {
    // std::remove_if(components.begin(), components.end(), [&](Component *a) { return *a == *cpt; });
}

Component *GameObject::getComponent(std::string type) {
    for (auto &cpt: components) {
        if (cpt->is(type)) {
            return cpt.get();
        }
    }
    return nullptr;
}
