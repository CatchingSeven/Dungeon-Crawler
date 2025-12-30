//
// Created by maxhe on 11/29/2025.
//
#include "../../include/world/TileMap.h"

#include <iostream>
#include <bits/fs_fwd.h>
#include <filesystem>


void TileMap::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();//just overwriting the sfml function I dont exactly know how it works under the hood

    states.texture = &tileset;

    target.draw(vertexArray, states);
}

bool TileMap::load(const std::string &filename, sf::Vector2u tileSize, const int *tiles, unsigned int width, unsigned int height) {
    //load tilset
    if (!tileset.loadFromFile(filename)) {
        return false;
    }


    vertexArray.setPrimitiveType(sf::Quads);// essentially each texture we want is a 32x32 block on the tilset, thus we use a quad
    vertexArray.resize(width * height * 4); // this is determined by the height and width of our map. we then multiply it by 4 as each tile is drawn as a quad, which is 4 vertices
    for (unsigned int i = 0; i < width; i++) {
        for (unsigned int j = 0; j < height; j++) {
            int tileNumber = tiles[i + j * width];
            int tilesetColumn = tileNumber % (tileset.getSize().x / tileSize.x);
            int tilesetRow = tileNumber / (tileset.getSize().x / tileSize.x);

            // pointer to current tiles quad
            sf::Vertex* quad = &vertexArray[(i + j * width) * 4];

            quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
            quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
            quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
            quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

            // define its 4 texture coordinates
            quad[0].texCoords = sf::Vector2f(tilesetColumn * tileSize.x, tilesetRow * tileSize.y);
            quad[1].texCoords = sf::Vector2f((tilesetColumn + 1) * tileSize.x, tilesetRow * tileSize.y);
            quad[2].texCoords = sf::Vector2f((tilesetColumn + 1) * tileSize.x, (tilesetRow + 1) * tileSize.y);
            quad[3].texCoords = sf::Vector2f(tilesetColumn * tileSize.x, (tilesetRow + 1) * tileSize.y);


        }
    }

    return true;
}
