#ifndef IDJ_ENGINE_FACE_H
#define IDJ_ENGINE_FACE_H

#include "Component.h"
#include "InputManager.h"

class Face : public Component {
private:
    int hitpoints;
    const int DEFAULT_HP = 30;

public:

    explicit Face(GameObject &associated);

    void damage(int damage);

    void update(float dt) override;

    void render() override;

    bool is(std::string type) override;

    int getHitpoints() const;
};

#endif //IDJ_ENGINE_FACE_H
