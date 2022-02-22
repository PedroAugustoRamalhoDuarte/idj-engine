//
// Created by pedro on 22/02/2022.
//

#include "CameraFollower.h"

void CameraFollower::update(float dt) {
    associated.box.x = Camera::pos.x;
    associated.box.y = Camera::pos.y;
}

void CameraFollower::render() {

}

bool CameraFollower::is(std::string type) {
    return "CameraFollower";
}

CameraFollower::CameraFollower(GameObject &go) : Component(go) {

}

void CameraFollower::start() {

}
