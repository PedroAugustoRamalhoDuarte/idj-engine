#ifndef IDJ_ENGINE_COMPONENT_H
#define IDJ_ENGINE_COMPONENT_H

class Component;

#include <iostream>
#include "GameObject.h"

class Component {
public:
    GameObject &associated; // Maybe needs to me protected

    explicit Component(GameObject &associated);

    virtual ~Component();

    virtual void update(float dt) = 0;

    virtual void render() = 0;

    virtual bool is(std::string type) = 0;
};

#endif //IDJ_ENGINE_COMPONENT_H
