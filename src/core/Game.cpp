//
// Created by maxhe on 11/29/2025.
//
#include "../../include/core/Game.h"

#include <iostream>


void Game::update(float dt, sf::Vector2f screenSize) {
    playerSystem.updatePlayer(dt, screenSize);



}

void Game::render(sf::RenderWindow &window) {
    window.clear();

    playerSystem.renderPlayer(window);

}