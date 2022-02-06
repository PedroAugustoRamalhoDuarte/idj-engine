//
// Created by pedro on 06/02/2022.
//

#ifndef IDJ_ENGINE_SOUND_H
#define IDJ_ENGINE_SOUND_H

#define INCLUDE_SDL
#define INCLUDE_SDL_MIXER

#include "../lib/SDL_include.h"
#include "iostream"
#include "Component.h"

class Sound : public Component {
private:
    Mix_Chunk *chunk;
    int channel;

public:
    explicit Sound(GameObject& associated);

    Sound(GameObject& associated, std::string file);

    ~Sound();

    void play(int times = -1);

    void stop();

    void open(std::string file);

    bool isOpen();

    // TODO: We need to implement this functions?
    void update(float dt) override;

    void render() override;

    bool is(std::string type) override;

};
#endif //IDJ_ENGINE_SOUND_H
