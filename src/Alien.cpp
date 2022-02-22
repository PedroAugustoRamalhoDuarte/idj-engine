//
// Created by pedro on 22/02/2022.
//

#include "Alien.h"
#include "Sprite.h"
#include "InputManager.h"
#include "Camera.h"
#include "Minion.h"
#include "State.h"
#include "Game.h"
#include "Assets.h"

void Alien::update(float dt) {
    auto input = InputManager::getInstance();


    if (input.mousePress(LEFT_MOUSE_BUTTON)) {
        // Shoot
        std::cout << "Shoot" << std::endl;
        auto action = Action(Action::ActionType::SHOOT, input.getMouseX() + Camera::pos.x,
                             input.getMouseY() + Camera::pos.y);
        taskQueue.emplace(action);
    } else if (input.mousePress(RIGHT_MOUSE_BUTTON)) {
        // Moves
        std::cout << "Moves" << std::endl;
        auto action = Action(Action::ActionType::MOVE, input.getMouseX() + Camera::pos.x,
                             input.getMouseY() + Camera::pos.y);
        taskQueue.emplace(action);
    }

    if (!taskQueue.empty()) {
        auto action = taskQueue.front();
        if (action.type == Action::ActionType::MOVE) {
            Vec2 actualPosition = associated.box.middle();
            auto dist = (action.pos - actualPosition).magnitude();
            auto needSpeed = dist / dt;

            // TODO: Maybe this if is wrong
            if (needSpeed < speed.magnitude()) {
                // If is there enough speed moves and removes task
                associated.box.x = action.pos.x;
                associated.box.y = action.pos.y;
                taskQueue.pop();
            } else {

            }

        } else {
            // Shoot action
            taskQueue.pop();
        }
    }

    if (hp <= 0) {
        associated.requestDelete();
    }
}

void Alien::render() {

}

void Alien::start() {
    std::cout << "Start" << std::endl;
    // TODO: Maybe so wrong
    std::shared_ptr<GameObject> spAlien(&associated);
    std::weak_ptr<GameObject> wkAlien = spAlien;
    auto goMinion = new GameObject();
    auto minion = new Minion(*goMinion, wkAlien, 0);
    goMinion->addComponent(minion);
    minionArray.emplace_back(Game::getInstance().getState().addObject(goMinion).lock());
    std::cout << "End" << std::endl;
}

bool Alien::is(std::string type) {
    return "Alien";
}


Alien::Alien(GameObject &associated, int nMinions) : Component(associated) {
    auto sprite = new Sprite(associated, Assets::getImg("alien.png"));
    associated.addComponent(sprite);

    hp = 30;
    speed = Vec2(30, 30);
}

Alien::~Alien() {
    minionArray.clear();
}

Alien::Action::Action(Alien::Action::ActionType type, float x, float y) {
    type = type;
    pos = Vec2(x, y);
}
