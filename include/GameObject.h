//
// Created by pedro on 06/02/2022.
//

#ifndef IDJ_ENGINE_GAMEOBJECT_H
#define IDJ_ENGINE_GAMEOBJECT_H

class GameObject;

#include <vector>
#include <iostream>
#include <memory>
#include "Component.h"
#include "Rect.h"

class GameObject {
private:

    bool isDead;

public:
    std::vector<std::unique_ptr<Component>> components; // DEBUG MOVE TO PRIVATE

    GameObject();

    ~GameObject();

    void update(float dt);

    void render();

    bool getIsDead();

    void requestDelete();

    void addComponent(Component *cpt);

    void removeComponent(Component *cpt);

    Component *getComponent(std::string);

    Rect box;

};

#endif //IDJ_ENGINE_GAMEOBJECT_H
