//
// Created by maxhe on 11/29/2025.
//

#ifndef ROOM__H
#define ROOM__H
#include <SFML/System/Vector2.hpp>
#include <vector>
#include <unordered_map>

#include "../world/TileMap.h"
#include "../enums/RoomState.h"

struct RoomID {
    //essentially, we use this to determine where the room fits into the broader dungeon. The dungeon will be a massive grid and the RoomID tells us where on the grid the room goes.
    int X;
    int Y;
    bool operator<(const RoomID& other) const {
    if (X != other.X) {
        return X < other.X;
    }

    return Y < other.Y;
}

};
struct Door {
    sf::Vector2i position;
    RoomID destinationRoom;
    sf::Vector2i arrivalPosition;
};

struct TileProperties {
    bool walkable;
};




class Room {
    private:
    RoomID id;
    RoomState state = RoomState::Unvisited;
    sf::Vector2i size;
    TileMap map;
    std::vector<int> level;
    std::unordered_map<int, TileProperties> tileProperties;
    std::vector<Door> doors;

public:
    Room();
    RoomID getRoomID();
    RoomState getRoomState();
    sf::Vector2i getSize();
    int getTile(int x, int y) const;
    bool isWalkable(int tileX, int tileY) const;
    void setRoomID(int x, int y);
    void setRoomState(RoomState state);
    void setSize(sf::Vector2i size);
    void render(sf::RenderWindow &window);
    void update(float dt);
    void loadLayout();
    void loadProperties();
    const Door* getDoorAt(int x, int y) const;
    



};

#endif //ROOM__H
