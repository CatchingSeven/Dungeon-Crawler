//
// Created by maxhe on 11/29/2025.
//
#include "../../include/entities/Player.h"
#include <iostream>

Player::Player() {
    this->position = {0, 0};
    texture.loadFromFile("../assets/Missing_Texture.png");
    sprite.setTexture(texture);



}

Player::~Player() {


}

void Player::update(float dt, sf::Vector2f screenSize) {
    float speed = 1000.f; // temp speed
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)||sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        position.y -= speed * dt;
        if (position.y <= 0) position.y += speed * dt;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)||sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        position.y += speed * dt;
        if (position.y >= screenSize.y*0.89f) position.y -= speed * dt;
        // this does work, but the sprite goes a little further off screen than expected
        std::cout << "ScreenSize: " << screenSize.y << "Current Pos y: " << position.y << std::endl;

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)||sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        position.x -= speed * dt;
        if (position.x <= 0) position.x += speed * dt;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)||sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        position.x += speed * dt;
        if (position.x >= screenSize.x*0.93f) position.x -= speed * dt;
        std::cout << "ScreenSize: " << screenSize.x << "Current Pos y: " << position.x << std::endl;
    }

    sprite.setPosition(position);


}

void Player::render(sf::RenderWindow& window) {


    window.draw(sprite);
}

