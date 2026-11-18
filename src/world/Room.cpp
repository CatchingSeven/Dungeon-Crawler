//
// Created by maxhe on 11/29/2025.
//
#include "../../include/world/Room.h"

#include <iostream>
#include <filesystem>
#include <fstream>
#include <sstream>

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

int Room::getTile(int x, int y) const {
    //std::cout << "Tile: "<< level[y * size.x + x] << std::endl;
    return level[y * size.x + x];
}

bool Room::isWalkable(int tileX, int tileY) const{
    int tile = getTile(tileX, tileY);


    return tileProperties.at(tile).walkable;

}

const Door* Room::getDoorAt(int x, int y) const {
    for (const Door& door : doors){
        if (door.position.x == x && door.position.y == y){
            return &door;
        }
    }

    return nullptr;
}

void Room::loadProperties(){
    std::filesystem::path path = std::filesystem::path(DUNGEON_ASSET_DIR) / "maps" / "tile_properties.csv";
    std::ifstream file(path);

    if (!file.is_open()) {
    std::cerr << "Failed to open properties file!" << std::endl;
    return; 
    }

    std::string line;

    while(std::getline(file, line)){
        std::stringstream stream(line);
        std::string id;
        std::string walkable;

        std::getline(stream, id, ',');
        std::getline(stream, walkable, ',');
        int idInt = std::stoi(id);


        TileProperties t;
        t.walkable = (walkable == "true");

        tileProperties[idInt] = t;

    }

}



void Room::loadLayout() { //will need to take in parameter for specific room, no we wont
    std::string fileName = std::to_string(id.X) + std::to_string(id.Y) + ".csv";
    
     
    std::filesystem::path path = std::filesystem::path(DUNGEON_ASSET_DIR) / "maps" / "rooms" / fileName;

    std::ifstream file(path);

    if (!file.is_open()) {
    std::cerr << "Failed to open room file!" << std::endl;
    return; 
    }

    std::string line;

    while(std::getline(file, line)){
        std::stringstream stream(line);
        std::string key;
        std::string value;

        std::getline(stream, key, ',');
        std::getline(stream, value, ',');
        

        if (key == "width"){
            size.x = std::stoi(value);
        }
        else if (key == "height")
        {
            size.y = std::stoi(value);
            
        }
        
        if (line == "tiles"){
            break;
        }
        
        


    }

    level.clear();
    level.reserve(size.x * size.y);
    
  

    while (std::getline(file, line)){
        if (line == "doors") {
            break;
        }
        std::stringstream stream(line);
        std::string value;
        
        while (std::getline(stream, value, ',')) {
            int x = std::stoi(value);
            level.push_back(x - 1);
        }
        
        

       


    }


    while (std::getline(file, line)) {
        std::stringstream stream(line);
        std::string value;
        int data[6];
        for (int i = 0; i < 6; i++) {
            std::getline(stream, value, ',');
            data[i] = std::stoi(value);
        }

        Door door;

        door.position = {data[0], data[1]};
        door.destinationRoom = {data[2], data[3]};
        door.arrivalPosition = {data[4], data[5]};

        doors.push_back(door);
    }

    

    /*std::cout << "Loaded tiles: " << level.size() << std::endl;
    std::cout << "Expected tiles: " << size.x * size.y << std::endl;*/



    if (!map.load("../assets/tilesets/Tileset.png", sf::Vector2u(64, 64), level, size.x, size.y)) {
        std::cerr << "Failed to load tilemap!" << std::endl;
    } else {
    std::cout << "Tilemap loaded successfully!" << std::endl;
}

    



}

void Room::render(sf::RenderWindow &window) {
    window.draw(map);

}




