//
// Created by pedro on 31/01/2022.
//

#include "../include/State.h"

State::State() {
//    GameObject gameObject;
//    bg = new Sprite(gameObject, "./assets/img/cachorro-caramelo.png");
    quitRequested = false;
    music = Music("./assets/audio/stageState.ogg");
    // music.play();

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
    // input();
    auto inputManager = InputManager::getInstance();


    if (inputManager.keyPress(SDLK_SPACE)) {
        std::cout << "Teste" << std::endl;
        Vec2 objPos = Vec2(200, 0).rotate(-PI + PI * (rand() % 1001) / 500.0) +
                      Vec2(inputManager.getMouseX(), inputManager.getMouseY());
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

            std::cout << mouseX << "," << mouseY << std::endl;
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
