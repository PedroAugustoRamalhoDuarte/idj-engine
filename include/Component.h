#ifndef IDJ_ENGINE_COMPONENT_H
#define IDJ_ENGINE_COMPONENT_H

#include <iostream>
#include "GameObject.h"

class Component {
protected:
    GameObject associated;

public:
    Component(GameObject& associated);
    virtual ~Component();
    virtual void update(float dt);
    virtual void render();
    virtual bool is(std::string type);
};
#endif //IDJ_ENGINE_COMPONENT_H
