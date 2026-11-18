//
// Created by maxhe on 11/29/2025.
//

#ifndef ENEMY_H
#define ENEMY_H
#include "../entities/Entity.h"
#include "../core/Stats.h"
#include "../enums/EnemyBehaviorType.h"
class Player;

class Enemy : public Entity {
private:
    Player* player = nullptr;

public:
    Enemy();
    ~Enemy() = default;
    void update(float dt, sf::Vector2f screenSize, const Room &room) override;
    void render(sf::RenderWindow& window) override;
};
#endif //ENEMY_H
