//
// Created by pedro on 31/01/2022.
//

#include "../include/State.h"

State::State() {
//    GameObject gameObject;
//    bg = new Sprite(gameObject, "./assets/img/cachorro-caramelo.png");
    quitRequested = false;
    music = Music("./assets/audio/stageState.ogg");
    music.play();
}

void State::loadAssets() {

}

void State::update(float dt) {
    input();
    for (long i; i < objectArray.size(); i++) {
        objectArray[i]->update(dt);
        if (objectArray[i]->getIsDead()) {
            objectArray.erase(objectArray.begin() + i);
        }
    }
    if (SDL_QuitRequested()) {
        quitRequested = true;
    }
}

void State::render() {
    for (long i; i < objectArray.size(); i++) {
        objectArray[i]->render();
    }
    // Render background
    // bg.render();
}

bool State::getQuitRequested() {
    return quitRequested;
}

State::~State() {
    objectArray.clear();
}

void State::input() {
    SDL_Event event;
    int mouseX, mouseY;

    // Obtenha as coordenadas do mouse
    SDL_GetMouseState(&mouseX, &mouseY);

    // SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário
    while (SDL_PollEvent(&event)) {

        // Se o evento for quit, setar a flag para terminação
        if (event.type == SDL_QUIT) {
            quitRequested = true;
        }

        // Se o evento for clique...
        if (event.type == SDL_MOUSEBUTTONDOWN) {

            // Percorrer de trás pra frente pra sempre clicar no objeto mais de cima
            for (int i = objectArray.size() - 1; i >= 0; --i) {
                // Obtem o ponteiro e casta pra Face.
                GameObject *go = (GameObject *) objectArray[i].get();
                // Nota: Desencapsular o ponteiro é algo que devemos evitar ao máximo.
                // O propósito do unique_ptr é manter apenas uma cópia daquele ponteiro,
                // ao usar get(), violamos esse princípio e estamos menos seguros.
                // Esse código, assim como a classe Face, é provisório. Futuramente, para
                // chamar funções de GameObjects, use objectArray[i]->função() direto.

                if (go->box.contains(mouseX, mouseY)) {
                    Face *face = (Face *) go->getComponent("Face");
                    if (nullptr != face) {
                        // Aplica dano
                        face->damage(std::rand() % 10 + 10);
                        // Sai do loop (só queremos acertar um)
                        break;
                    }
                }
            }
        }
        if (event.type == SDL_KEYDOWN) {
            // Se a tecla for ESC, setar a flag de quit
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                quitRequested = true;
            }
                // Se não, crie um objeto
            else {
                Vec2 objPos = Vec2(200, 0).rotate(-PI + PI * (rand() % 1001) / 500.0) + Vec2(mouseX, mouseY);
                addObject((int) objPos.x, (int) objPos.y);
            }
        }
    }
}

void State::addObject(int mouseX, int mouseY) {
    GameObject gameObject;
    Sprite sprite(gameObject, "./assets/img/penguinface.png");
    // Maybe needs setClip
    gameObject.addComponent(&sprite);

    Sound sound(gameObject, "./assets/audio/boom.wav");
    Face face(gameObject);
    gameObject.addComponent(&sound);
    gameObject.addComponent(&face);

    objectArray.emplace_back(&gameObject);
}
