#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <SFML/Window.hpp>

int main() {
    sf::Window window(sf::VideoMode(800, 800), "Dungeon Crawler Window test");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }



    return 0;
}