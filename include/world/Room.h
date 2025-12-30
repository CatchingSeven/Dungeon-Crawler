//
// Created by maxhe on 11/29/2025.
//

#ifndef ROOM__H
#define ROOM__H
#include <SFML/System/Vector2.hpp>

#include "../world/TileMap.h"
#include "../enums/RoomState.h"

struct Door;

struct RoomID {
    //essentially, we use this to determine where the room fits into the broader dungeon. The dungeon will be a massive grid and the RoomID tells us where on the grid the room goes.
    int X;
    int Y;
};

class Room {
    private:
    RoomID id;
    RoomState state = RoomState::Unvisited;
    sf::Vector2i size;
    TileMap map;

public:
    Room();
    RoomID getRoomID();
    RoomState getRoomState();
    sf::Vector2i getSize();
    void setRoomID(int x, int y);
    void setRoomState(RoomState state);
    void setSize(sf::Vector2i size);
    void render(sf::RenderWindow &window);
    void update(float dt);
    void loadLayout();


};

#endif //ROOM__H
