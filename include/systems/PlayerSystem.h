//
// Created by maxhe on 11/29/2025.
//

#ifndef PLAYERSYSTEM_H
#define PLAYERSYSTEM_H
#include "../entities/Player.h"
#include "../world/DungeonLayout.h"
#include <optional>

struct Door;

class PlayerSystem {
private:
    Player player;
    public:
    const Door* updatePlayer(float dt, sf::Vector2f screenSize, const Room &room);
    void renderPlayer(sf::RenderWindow &window);
    


};


#endif //PLAYERSYSTEM_H
