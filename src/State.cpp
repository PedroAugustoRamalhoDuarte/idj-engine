//
// Created by pedro on 31/01/2022.
//

#include "../include/State.h"
#include "Camera.h"
#include "CameraFollower.h"

State::State() {
    quitRequested = false;
    started = false;

    // Initialize Background
    auto backgroundObject = new GameObject;
    auto bgSprite = new Sprite(*backgroundObject, "./assets/img/ocean.jpg");
    bgSprite->setClip(0, 0, SCREEN_W, SCREEN_H);
    auto cameraFollower = new CameraFollower(*backgroundObject);
    backgroundObject->addComponent(bgSprite);
    backgroundObject->addComponent(cameraFollower);
    objectArray.emplace_back(backgroundObject);

    // Music
    music = Music("./assets/audio/stageState.ogg");
    // music.play();

    // Map
    auto gameObject = new GameObject();
    gameObject->box.x = 0;
    gameObject->box.y = 0;
    auto tileSet = new TileSet(64, 64, "./assets/img/tileset.png");
    auto tileMap = new TileMap(*gameObject, "./assets/map/tileMap.txt", tileSet);
    gameObject->addComponent(tileMap);
    objectArray.emplace_back(gameObject);
}

void State::loadAssets() {

}

void State::update(float dt) {
    auto inputManager = InputManager::getInstance();

    Camera::update(dt);

    if (inputManager.keyPress(SDLK_SPACE)) {
        Vec2 objPos = Vec2(200, 0).rotate(-PI + PI * (rand() % 1001) / 500.0) +
                      Vec2(inputManager.getMouseX() + Camera::pos.x, inputManager.getMouseY() + Camera::pos.y);
        addObject((int) objPos.x, (int) objPos.y);
    }

    for (long i = 0; i < objectArray.size(); i++) {
        objectArray[i]->update(dt);
        if (objectArray[i]->getIsDead()) {
            objectArray.erase(objectArray.begin() + i);
            std::cout << objectArray.size() << std::endl;
        }
    }

    if (SDL_QuitRequested() or inputManager.isQuitRequested()) {
        quitRequested = true;
    }
}

void State::render() {
    for (long i = 0; i < objectArray.size(); i++) {
        objectArray[i]->render();
    }
    // Render background
    // bg.render();
}

bool State::getQuitRequested() {
    return quitRequested;
}

State::~State() {
    // objectArray.clear();
}

void State::addObject(int mouseX, int mouseY) {
    auto gameObject = new GameObject();
    gameObject->box.x = mouseX;
    gameObject->box.y = mouseY;

    // Adds Sprite
    auto sprite = new Sprite(*gameObject, "./assets/img/penguinface.png");
    gameObject->addComponent(sprite);

    // Adds Sound
    auto sound = new Sound(*gameObject, "./assets/audio/boom.wav");
    gameObject->addComponent(sound);

    // Adds Face
    auto face = new Face(*gameObject);
    gameObject->addComponent(face);

    objectArray.emplace_back(gameObject);
}

void State::start() {
    loadAssets();

    for (auto obj: objectArray) {
        obj->start();
    }

    started = true;
}

std::weak_ptr<GameObject> State::addObject(GameObject *go) {
    std::shared_ptr<GameObject> sharedPtr(go);
    objectArray.push_back(sharedPtr);

    if (started) {
        go->start();
    }
    return std::weak_ptr<GameObject>(sharedPtr);
}

std::weak_ptr<GameObject> State::getObjectPtr(GameObject *go) {
    for (const auto &obj: objectArray) {
        if (obj.get() == go) {
            return std::weak_ptr<GameObject>(obj);
        }
    }
    return std::weak_ptr<GameObject>();
}
