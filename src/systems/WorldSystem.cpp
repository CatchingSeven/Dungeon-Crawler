//
// Created by maxhe on 11/29/2025.
//
#include "../../include/systems/WorldSystem.h"

#include <iostream>
#include <filesystem>


namespace fs = std::filesystem;



void WorldSystem::loadRoom(RoomID id) {
    //if (dungeonLayout.hasRoom(id)){
    std::cout << "Room ID has reached WorldSystem::loadRoom " + std::to_string(id.X) + std::to_string(id.Y);
        room = dungeonLayout.getRoom(id);
        room.loadLayout();
        room.loadProperties();
    //}
    

    


}

void WorldSystem::loadRooms(){
    fs::path directory = fs::path(DUNGEON_ASSET_DIR) / "maps" / "rooms";

for (const fs::directory_entry& entry : fs::directory_iterator(directory)) {
    if (entry.is_regular_file() && entry.path().extension() == ".csv") { //room files must use the format of xy.csv (i.e. 01.csv). wont be inserted if not digits
        std::cout << entry.path().filename() << '\n';
        std::string name = entry.path().stem().string();
        if (std::isdigit(name[0]) && std::isdigit(name[1])) {
            int x = name[0] - '0';
            int y = name[1] - '0';
            Room newRoom;
            newRoom.setRoomID(x, y);
            dungeonLayout.addRoom(newRoom.getRoomID(), newRoom);
            
        }
        
    }
}

}

Room WorldSystem::getRoom(){
    return room;
}


void WorldSystem::updateWorld(float dt, sf::Vector2f screenSize) {

}
void WorldSystem::renderWorld(sf::RenderWindow &window) {
    room.render(window);
}
