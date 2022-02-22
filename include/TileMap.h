//
// Created by pedro on 14/02/2022.
//

#ifndef IDJ_ENGINE_TILEMAP_H
#define IDJ_ENGINE_TILEMAP_H


#include <vector>
#include "Component.h"
#include "TileSet.h"

class TileMap : public Component {

private:
    std::vector<int> tileMatrix;
    TileSet *tileSet;
    int mapWidth;
    int mapHeight;
    int mapDepth;

public:
    explicit TileMap(GameObject &associated);

    TileMap(GameObject &associated, std::string file, TileSet *tileSet);

    ~TileMap();

    void load(std::string file);

    void setTileSet(TileSet *tileSet);

    int &at(int x, int y, int z = 0);

    void start() override;

    void update(float dt) override;

    void render() override;

    bool is(std::string type) override;

    void renderLayer(int layer, int cameraX = 0, int cameraY = 0);

    int getWidth();

    int getHeight();

    int getDepth();
};


#endif //IDJ_ENGINE_TILEMAP_H
