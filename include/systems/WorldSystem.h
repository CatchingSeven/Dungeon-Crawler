//
// Created by maxhe on 11/29/2025.
//

#ifndef WORLDSYSTEM_H
#define WORLDSYSTEM_H
#include "../world/DungeonLayout.h"
#include "../world/Room.h"
class Player;

class WorldSystem {
private:
    Player* player;
    Room room;
public:
    void loadRoom();
    void updateWorld(float dt, sf::Vector2f screenSize);
    void renderWorld(sf::RenderWindow &window);

};
#endif //WORLDSYSTEM_H
