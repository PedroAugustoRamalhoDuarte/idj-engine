//
// Created by pedro on 14/02/2022.
//

#ifndef IDJ_ENGINE_TILESET_H
#define IDJ_ENGINE_TILESET_H


#include "Sprite.h"

class TileSet {
private:
    Sprite *tileSet;

    int rows;
    int columns;
    int tileWidth;
    int tileHeight;
public:

    TileSet(int tileWidth, int tileHeight, std::string file);

    int getTileWidth();

    int getTileHeight();

    void renderTile(unsigned index, float x, float y);

};


#endif //IDJ_ENGINE_TITLESET_H
