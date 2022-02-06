#ifndef IDJ_ENGINE_FACE_H
#define IDJ_ENGINE_FACE_H

#include "Component.h"

class Face : public Component {
private:
    int hitpoints;
    const int DEFAULT_HP = 30;

public:

    Face(GameObject &associated);

    void damage(int damage);

    void update(float dt) override;

    void render() override;

    bool is(std::string type) override;
};

#endif //IDJ_ENGINE_FACE_H
