//
// Created by maxhe on 11/29/2025.
//

#include "../../include/core/GameApp.h"

void GameApp::run() {
    window.create(sf::VideoMode(800, 600), "Dungeon Crawler v0.1.2");
    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        float dt = clock.restart().asSeconds();
        game.update(dt);
        window.clear(sf::Color::White);
        game.render(window);
        window.display();
    }

}
