//
// Created by maxhe on 11/29/2025.
//

#ifndef TILEMAP__H
#define TILEMAP__H
#include <SFML/Graphics.hpp>
class TileMap : public sf::Drawable, public sf::Transformable{
private:
    sf::VertexArray vertexArray;
    sf::Texture tileset;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;//here we overwrite the draw method we inherited from sf::drawable

public:
    bool load(const std::string& filename, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);
};
#endif //TILEMAP__H
