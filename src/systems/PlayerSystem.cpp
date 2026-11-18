//
// Created by maxhe on 11/29/2025.
//
#include "../../include/systems/PlayerSystem.h"

const Door* PlayerSystem::updatePlayer(float dt, sf::Vector2f screenSize, const Room &room) {
   player.update(dt, screenSize, room);
   return player.walkThroughDoor(room);
}
void PlayerSystem::renderPlayer(sf::RenderWindow &window) {


   player.render(window);
}

