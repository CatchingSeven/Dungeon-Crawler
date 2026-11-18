//
// Created by maxhe on 11/29/2025.
//
#include "../../include/entities/Enemy.h"

#include <filesystem>
#include <stdexcept>

// Placeholder stats and texture for AI development.
Enemy::Enemy() {
    position = {100, 100};
    const auto texturePath = std::filesystem::path(DUNGEON_ASSET_DIR) / "Missing_Texture.png";
    if (!texture.loadFromFile(texturePath.string())) {
        throw std::runtime_error("Could not load the enemy placeholder texture");
    }
    sprite.setTexture(texture);
    sprite.setPosition(position);

    stats.HP = 100;
    stats.MaxHP = stats.HP;
    stats.attack = 10;
    stats.defense = 10;
    stats.speed = 1000;
    stats.mana = 100;
}

void Enemy::update(float, sf::Vector2f, const Room &room) {
    sprite.setPosition(position);
}

void Enemy::render(sf::RenderWindow& window) {
    window.draw(sprite);
}
