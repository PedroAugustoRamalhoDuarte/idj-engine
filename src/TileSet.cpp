//
// Created by pedro on 14/02/2022.
//

#include "TileSet.h"

TileSet::TileSet(int tileWidth, int tileHeight, std::string file) {
    this->tileWidth = tileWidth;
    this->tileHeight = tileHeight;

    auto gameSprite = new GameObject();
    tileSet = new Sprite(*gameSprite, file);
    rows = tileSet->getWidth() / tileWidth;
    columns = tileSet->getHeight() / tileHeight;
}

void TileSet::renderTile(unsigned int index, float x, float y) {
    if (index < rows * columns) {
        tileSet->setClip(x, y, tileWidth, tileHeight);
        tileSet->render(x, y);
    } else {
        std::cout << "Index error renderTile" << std::endl;
    }
}

int TileSet::getTileWidth() {
    return tileWidth;
}

int TileSet::getTileHeight() {
    return tileHeight;
}
