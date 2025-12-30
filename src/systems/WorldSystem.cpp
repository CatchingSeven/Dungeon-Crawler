//
// Created by maxhe on 11/29/2025.
//
#include "../../include/systems/WorldSystem.h"

#include <iostream>
#include <filesystem>
void WorldSystem::loadRoom() {

    room.loadLayout();


}


void WorldSystem::updateWorld(float dt, sf::Vector2f screenSize) {

}
void WorldSystem::renderWorld(sf::RenderWindow &window) {
    room.render(window);
}
