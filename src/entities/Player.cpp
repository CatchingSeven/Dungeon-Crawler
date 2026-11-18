//
// Created by maxhe on 11/29/2025.
//
#include "../../include/entities/Player.h"
#include <filesystem>
#include <iostream>
#include <stdexcept>
#include "../../include/world/Room.h"


Player::Player() {
    this->position = {160, 160};
    const std::filesystem::path assetDirectory(DUNGEON_ASSET_DIR);
    const auto playerTexture = assetDirectory / "sprites/player.png";
    const auto fallbackTexture = assetDirectory / "Missing_Texture.png";
    if (!std::filesystem::exists(playerTexture) || !texture.loadFromFile(playerTexture.string())) {
        std::cerr << "Player texture unavailable: " << playerTexture
                  << ". Using " << fallbackTexture << '\n';
        if (!texture.loadFromFile(fallbackTexture.string())) {
            throw std::runtime_error("Could not load the player texture or its fallback");
        }
    }
    sprite.setTexture(texture);
    
    sprite.setPosition(position);
    /* proof of concept, doesnt do anything rn, except for speed */
    stats.HP = 100;
    stats.MaxHP = stats.HP;
    stats.attack = 10;
    stats.defense = 10;
    stats.speed = 200;
    stats.mana = 100;




}

Player::~Player() {


}



void Player::update(float dt, sf::Vector2f screenSize, const Room &room) {
    float speed = (float)stats.speed;
    sf::Vector2f nextPosition = position;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)||sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        nextPosition.y -= speed * dt;
        if (nextPosition.y <= 0) nextPosition.y += speed * dt;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)||sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        nextPosition.y += speed * dt;
        if (nextPosition.y >= screenSize.y*0.95f) nextPosition.y -= speed * dt;
        // this does work, but the sprite goes a little further off screen than expected


    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)||sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        nextPosition.x -= speed * dt;
        if (nextPosition.x <= 0) nextPosition.x += speed * dt;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)||sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        nextPosition.x += speed * dt;
        if (nextPosition.x >= screenSize.x*0.95f) nextPosition.x -= speed * dt;
        
    }

    int tileX = static_cast<int>(nextPosition.x / 64.f);
    int tileY = static_cast<int>(nextPosition.y / 64.f);
    

    if (room.isWalkable(tileX, tileY)) {
    position = nextPosition;
    sprite.setPosition(position);
    
}
}



const Door* Player::walkThroughDoor(const Room& room) {
    int tileX = static_cast<int>(position.x / 64.f);
    int tileY = static_cast<int>(position.y / 64.f);
    return room.getDoorAt(tileX, tileY);
}

    




void Player::render(sf::RenderWindow& window) {


    window.draw(sprite);
}

