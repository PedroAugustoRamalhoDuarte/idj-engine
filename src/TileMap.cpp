//
// Created by pedro on 14/02/2022.
//

#include <fstream>
#include "../include/TileMap.h"
#include "Camera.h"

void TileMap::update(float dt) {

}

void TileMap::render() {
    for (auto z = 0; z < mapDepth; ++z) {
        renderLayer(z, Camera::pos.x, Camera::pos.y);
    }
}

void TileMap::renderLayer(int layer, int cameraX, int cameraY) {
    auto cont = 0;
    for (auto x = 0; x < mapWidth; x++) {
        for (auto y = 0; y < mapHeight; y++) {
            tileSet->renderTile(tileMatrix[cont + (layer * (mapWidth * mapHeight))],
                                x * tileSet->getTileWidth() + (associated.box.x - cameraX),
                                y * tileSet->getTileHeight() + (associated.box.y - cameraY));
            cont++;
        }
    }

}


bool TileMap::is(std::string type) {
    return "TitleMap";
}

TileMap::TileMap(GameObject &associated) : Component(associated) {
    // TODO
}

TileMap::TileMap(GameObject &associated, std::string file, TileSet *tileSet) : TileMap(associated) {
    this->tileSet = tileSet;
    load(file);
}

std::vector<std::string> split(std::string line, std::string del = " ") {
    std::vector<std::string> vector;
    int start = 0;
    int end = line.find(del);
    while (end != -1) {
        vector.push_back(line.substr(start, end - start));
        start = end + del.size();
        end = line.find(del, start);
    }
    vector.push_back(line.substr(start, end - start));
    return vector;
}

void TileMap::load(std::string file) {
    std::fstream arquivo;

    arquivo.open(file);

    std::string line;
    // Parse first line
    std::getline(arquivo, line);
    auto firstLineSplited = split(line, ",");
    mapWidth = std::stoi(firstLineSplited[0]);
    mapHeight = std::stoi(firstLineSplited[1]);
    mapDepth = std::stoi(firstLineSplited[2]);

    // Get Blank Line

    // Get lines
    while (!arquivo.eof()) {
        std::getline(arquivo, line);
        if (!line.empty()) {
            for (const auto &line_splited: split(line, ",")) {
                if (!line_splited.empty()) {
                    tileMatrix.push_back(std::stoi(line_splited) - 1);
                }
            }
        }
    }
    arquivo.close();
}

TileMap::~TileMap() {

}

int TileMap::getWidth() {
    return mapWidth;
}

int TileMap::getHeight() {
    return mapHeight;
}

int TileMap::getDepth() {
    return mapDepth;
}

void TileMap::setTileSet(TileSet *tileSet) {
    this->tileSet = tileSet;
}

int &TileMap::at(int x, int y, int z) {
    return tileMatrix[z * (mapWidth * mapHeight) + x + y * mapWidth];
}

void TileMap::start() {

}
