//
// Created by maxhe on 11/29/2025.
//
#include "../../include/systems/PlayerSystem.h"

void PlayerSystem::updatePlayer(float dt, sf::Vector2f screenSize) {
   player.update(dt, screenSize);
}
void PlayerSystem::renderPlayer(sf::RenderWindow &window) {


   player.render(window);
}