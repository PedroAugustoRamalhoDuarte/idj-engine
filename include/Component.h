#ifndef IDJ_ENGINE_COMPONENT_H
#define IDJ_ENGINE_COMPONENT_H

#include <iostream>

class Component {
protected:
    // GameObject associated;

public:
    // Component(GameObject& associated);
    virtual ~Component();
    virtual void update();
    virtual void render();
    virtual bool is(std::string type);
};
#endif //IDJ_ENGINE_COMPONENT_H
