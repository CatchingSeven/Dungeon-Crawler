//
// Created by maxhe on 11/29/2025.
//
#include "../../include/core/Game.h"

#include <iostream>

void Game::init() {
    RoomID id;
    id.X = 0;
    id.Y = 0;
    worldSystem.loadRooms();
    worldSystem.loadRoom(id);
    
}
void Game::update(float dt, sf::Vector2f screenSize) {
    const Door* door = playerSystem.updatePlayer(dt, screenSize, worldSystem.getRoom());
    std::cout << "Door detected: " << (door != nullptr) << '\n';
    if (door != nullptr){
        std::cout << "Room ID has reached WorldSystem::loadRoom " + std::to_string(door->destinationRoom.X) + std::to_string(door->destinationRoom.Y);
        
        worldSystem.loadRoom(door->destinationRoom);
    }



}

void Game::render(sf::RenderWindow &window) {
    window.clear();
    worldSystem.renderWorld(window);

    playerSystem.renderPlayer(window);

}