//
// Created by maxhe on 11/29/2025.
//

#ifndef GAMEAPP_H
#define GAMEAPP_H
#include "Game.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>



class GameApp {
    private:
    sf::RenderWindow window;
    Game game;
    sf::Vector2f screenSize;
    public:
    void run();
};



#endif //GAMEAPP_H
