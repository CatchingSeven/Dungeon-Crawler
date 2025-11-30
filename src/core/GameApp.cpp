//
// Created by maxhe on 11/29/2025.
//

#include "../../include/core/GameApp.h"

#include <iostream>

void GameApp::run() {

    /* Temp dev tools */
    window.create(sf::VideoMode(1920, 1080), "Dungeon Crawler v0.1.2");
    sf::Clock clock;
    sf::Time dt = clock.getElapsedTime();
    sf::Text fps;
    sf::Font font;
    if (!font.loadFromFile("../assets/fonts/DejaVuSans.ttf")) {
        std::cerr << "Failed to load font" << std::endl;
    }
    font.loadFromFile("../assets/fonts/DejaVuSans.ttf");
    fps.setFont(font);
    fps.setCharacterSize(40);
    fps.setColor(sf::Color::Red);
    fps.setPosition(10.f, 10.f);
    fps.setString("FPS");
    screenSize =  sf::Vector2f(window.getSize());

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }







        float dt = clock.restart().asSeconds();

        float currentFPS = 1.f / dt;






        fps.setString("FPS: " + std::to_string(currentFPS));

        game.update(dt, screenSize);
        window.clear();
        window.draw(fps);
        game.render(window);
        window.display();
    }

}
