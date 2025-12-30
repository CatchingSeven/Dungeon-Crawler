//
// Created by maxhe on 11/29/2025.
//
#include "../../include/world/Room.h"

#include <iostream>
#include <filesystem>

#include "../../include/enums/TileType.h"
#include "../../include/world/ProceduralGenerator.h"

Room::Room() {

}

RoomState Room::getRoomState() {
    return state;
}
void Room::setRoomID(int x, int y) {
    id.X = x;
    id.Y = y;
}

void Room::setRoomState(RoomState state) {
    this->state = state;
}

void Room::setSize(sf::Vector2i size) {
    this->size = size;
}

RoomID Room::getRoomID() {
    return id;
}

sf::Vector2i Room::getSize() {
    return size;
}

void Room::loadLayout() {
    ProceduralGenerator generator;

    int level[64*64];
   generator.generateGenericRoom(64, 64, level);



    if (!map.load("../assets/tilesets/Tileset.png", sf::Vector2u(64, 64), level, 16, 8)) {

    }



}

void Room::render(sf::RenderWindow &window) {
    window.draw(map);

}




