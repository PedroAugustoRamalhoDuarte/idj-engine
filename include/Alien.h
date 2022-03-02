//
// Created by pedro on 22/02/2022.
//

#ifndef IDJ_ENGINE_ALIEN_H
#define IDJ_ENGINE_ALIEN_H


#include <queue>
#include "Component.h"
#include "GameObject.h"
#include "Vec2.h"

class Alien : public Component {
private:
    class Action {
    public:
        enum class ActionType {
            MOVE, SHOOT
        };

        ActionType type;

        Vec2 pos;

        Action(ActionType type, float x, float y);
    };

    Vec2 speed;
    int hp;
    int nMinions;

    std::queue<Action> taskQueue;
    std::vector<std::weak_ptr<GameObject>> minionArray;

public:
    Alien(GameObject &associated, int nMinions);

    ~Alien();

    void update(float dt) override;

    void render() override;

    void start() override;

    bool is(std::string type) override;
};


#endif //IDJ_ENGINE_ALIEN_H
