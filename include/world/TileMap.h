//
// Created by maxhe on 11/29/2025.
//

#ifndef TILEMAP_H
#define TILEMAP_H
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
class TileMap : public sf::Drawable, public sf::Transformable{
private:
    sf::VertexArray vertexArray;
    sf::Texture tileset;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;//here we overwrite the draw method we inherited from sf::drawable

public:
    bool load(const std::string& filename, sf::Vector2u tileSize, const std::vector<int>& tiles, unsigned int width, unsigned int height);
};
#endif //TILEMAP_H
