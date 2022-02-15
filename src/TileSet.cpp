//
// Created by pedro on 14/02/2022.
//

#include "TileSet.h"

TileSet::TileSet(int tileWidth, int tileHeight, std::string file) {
    this->tileWidth = tileWidth;
    this->tileHeight = tileHeight;

    auto gameSprite = new GameObject();
    tileSet = new Sprite(*gameSprite, file);

    rows = std::round(tileSet->getWidth() / tileWidth);
    columns = std::round(tileSet->getHeight() / tileHeight);
}

void TileSet::renderTile(unsigned int index, float x, float y) {
    if (index <= (rows * columns) - 1) {
        auto row = std::round(index / columns);
        auto col = std::round(index % columns);

        tileSet->setClip(col * tileWidth, row * tileHeight, tileWidth, tileHeight);
        tileSet->render(x, y);
    }
}

int TileSet::getTileWidth() {
    return tileWidth;
}

int TileSet::getTileHeight() {
    return tileHeight;
}
