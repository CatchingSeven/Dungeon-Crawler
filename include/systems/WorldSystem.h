//
// Created by maxhe on 11/29/2025.
//

#ifndef WORLDSYSTEM_H
#define WORLDSYSTEM_H
#include "../world/DungeonLayout.h"
#include "../world/Room.h"
#include <filesystem>
#include <iostream>
class Player;

struct RoomID;

class WorldSystem {
private:
    Player* player;
    Room room;
    DungeonLayout dungeonLayout;
public:
    void loadRooms();
    void loadRoom(RoomID id);
    void updateWorld(float dt, sf::Vector2f screenSize);
    void renderWorld(sf::RenderWindow &window);
    Room getRoom();
    

};
#endif //WORLDSYSTEM_H
