//
// Created by maxhe on 11/29/2025.
//

#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>

#include "../core/Stats.h"

class Room;
class Entity {
private:

protected:
    Stats stats;
    sf::Sprite sprite;
    sf::Vector2f position;
    sf::Texture texture;
public:
    void setPosition(float x, float y) {
        position = {x, y};
    }
    sf::Vector2f getPosition() const { // defined in header because its really unesscessary to have seperate src file for this and every item, enemy and player uses it.
        return position;
    }
    // Remember: Virtual is used to state "If child has own defintion of this method, use that method, and it is equal to zero to force the derived class to define its own method.
    virtual void update(float dt, sf::Vector2f screenSize, const Room &room) = 0;// each derived class MUST declare and define it's own update and render. this is how we enforce it.
    virtual void render(sf::RenderWindow& window) = 0;

};
#endif //ENTITY_H
