//
// Created by maxhe on 11/29/2025.
//

#ifndef PLAYER_H
#define PLAYER_H
#include "../entities/Entity.h"
#include "../core/Stats.h"
#include "../items/Inventory.h"
#include <optional>

struct Door;
class Player : public Entity {
    private:



public:
    Player();
    ~Player();
    void update(float dt, sf::Vector2f screenSize, const Room &room) override;
    void render(sf::RenderWindow& window) override;
    const Door* walkThroughDoor(const Room& room);
    


};
#endif //PLAYER_H
