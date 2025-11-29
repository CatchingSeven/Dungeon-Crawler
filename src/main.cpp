#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Dungeon Crawler Window test");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.display();
    }



    return 0;
}