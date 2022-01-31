#ifndef IDJ_ENGINE_STATE_H
#define IDJ_ENGINE_STATE_H

#include "Sprite.h"
#include "Music.h"

class State {
private:
    Music music;
    Sprite bg;
    bool quitRequested;

public:
    State();

    bool getQuitRequested();

    void loadAssets();

    void update(float dt);

    void render();
};


#endif //IDJ_ENGINE_STATE_H
