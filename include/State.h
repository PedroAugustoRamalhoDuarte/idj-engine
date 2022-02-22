#ifndef IDJ_ENGINE_STATE_H
#define IDJ_ENGINE_STATE_H

#include <memory>
#include "Sprite.h"
#include "Music.h"
#include "Face.h"
#include "Vec2.h"
#include "Sound.h"
#include "TileMap.h"
#include "InputManager.h"

#define SCREEN_W 1024
#define SCREEN_H 600

class State {
private:
    Music music;
    // Sprite bg;
    bool quitRequested;
    bool started;
    std::vector<std::shared_ptr<GameObject>> objectArray;

public:
    State();

    ~State();

    void start();

    bool getQuitRequested();

    void loadAssets();

    void update(float dt);

    void render();

    void addObject(int mouseX, int mouseY);

    std::weak_ptr<GameObject> addObject(GameObject *go);

    std::weak_ptr<GameObject> getObjectPtr(GameObject *go);
};


#endif //IDJ_ENGINE_STATE_H
