//
// Created by maxhe on 11/29/2025.
//

#ifndef PLAYER_H
#define PLAYER_H
#include "../entities/Entity.h"
#include "../core/Stats.h"
#include "../items/Inventory.h"
class Player : public Entity {
    private:



public:
    Player();
    ~Player();
    void update(float dt, sf::Vector2f screenSize) override;
    void render(sf::RenderWindow& window) override;


};
#endif //PLAYER_H
