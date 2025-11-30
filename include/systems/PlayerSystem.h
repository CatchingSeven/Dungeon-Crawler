//
// Created by maxhe on 11/29/2025.
//

#ifndef PLAYERSYSTEM_H
#define PLAYERSYSTEM_H
#include "../entities/Player.h"
#include "../world/DungeonLayout.h"
#

class PlayerSystem {
private:
    Player player;
    public:
    void updatePlayer(float dt, sf::Vector2f screenSize);
    void renderPlayer(sf::RenderWindow &window);


};


#endif //PLAYERSYSTEM_H
