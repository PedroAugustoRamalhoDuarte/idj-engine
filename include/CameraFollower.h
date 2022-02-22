//
// Created by pedro on 22/02/2022.
//

#ifndef IDJ_ENGINE_CAMERAFOLLOWER_H
#define IDJ_ENGINE_CAMERAFOLLOWER_H


#include "Component.h"
#include "Camera.h"

class CameraFollower : public Component {
public:
    explicit CameraFollower(GameObject &go);

    void update(float dt) override;

    void render() override;

    bool is(std::string type) override;
};


#endif //IDJ_ENGINE_CAMERAFOLLOWER_H
