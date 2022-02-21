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

class State {
private:
    Music music;
    // Sprite bg;
    bool quitRequested;
    std::vector<std::unique_ptr<GameObject>> objectArray;

public:
    State();

    ~State();

    bool getQuitRequested();

    void loadAssets();

    void update(float dt);

    void render();

    void input();

    void addObject(int mouseX, int mouseY);
};


#endif //IDJ_ENGINE_STATE_H
