//
// Created by pedro on 22/02/2022.
//

#ifndef IDJ_ENGINE_MINION_H
#define IDJ_ENGINE_MINION_H


#include "Component.h"
#include "Vec2.h"

class Minion : public Component {
private:
    constexpr static float MINION_VEL = PI / 10;
    GameObject *alienCenter;
    float arc;
public:
    // Changes pointer do std::weak
    Minion(GameObject &associated, GameObject *alienCenter, float arcOffSetDeg = 0);

    void shoot(Vec2 target);

    void update(float dt) override;

    void render() override;

    void start() override;

    bool is(std::string type) override;

};


#endif //IDJ_ENGINE_MINION_H
