//
// Created by pedro on 22/02/2022.
//

#ifndef IDJ_ENGINE_BULLET_H
#define IDJ_ENGINE_BULLET_H


#include "Component.h"

class Bullet : public Component {
private:
    Vec2 speed;
    float distanceLeft;
    int damage;
public:
    Bullet(GameObject &associated, float angle, float speed, int damage, float maxDistance, std::string sprite);

    void update(float dt) override;

    void render() override;

    void start() override;

    bool is(std::string type) override;

    int getDamage() const;
};


#endif //IDJ_ENGINE_BULLET_H
