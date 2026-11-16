//
// Created by maxhe on 11/29/2025.
//

#include "../../include/core/GameApp.h"

#include <iostream>

void GameApp::run() {

    /* Temp dev tools */
    window.create(sf::VideoMode(1920, 1080), "Dungeon Crawler Alpha build - v0.2.1v - TileMapping");
    sf::Clock clock;
    sf::Time dt = clock.getElapsedTime();

    screenSize =  sf::Vector2f(window.getSize());
    game.init();

    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }







        float dt = clock.restart().asSeconds();

        float currentFPS = 1.f / dt;








        game.update(dt, screenSize);
        window.clear();
        game.render(window);
        window.display();
    }

}
