#include <algorithm>
#include "../include/GameObject.h"

GameObject::GameObject() {
    isDead = false;
}

GameObject::~GameObject() {
    for (Component *cpt: components) {
        delete (cpt);
    }
}

void GameObject::update(float dt) {
    for (Component *cpt: components) {
        cpt->update(dt);
    }
}

void GameObject::render() {
    for (Component *cpt: components) {
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
    components.push_back(cpt);
}

// TODO: Build this function
void GameObject::removeComponent(Component *cpt) {
    // std::remove_if(components.begin(), components.end(), [&](Component *a) { return *a == *cpt; });
}

Component *GameObject::getComponent(std::string type) {
    for (Component *cpt: components) {
        if (cpt->is(type)) {
            return cpt;
        }
    }
    return nullptr;
}
