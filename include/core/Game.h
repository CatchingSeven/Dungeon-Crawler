//
// Created by maxhe on 11/29/2025.
//

#ifndef GAME_H
#define GAME_H
#include "../systems/WorldSystem.h"
#include "../systems/PlayerSystem.h"
#include "../systems/EnemySystem.h"
#include "../systems/CombatSystem.h"
#include "../systems/ItemSystem.h"
#include "../systems/UISystem.h"
#include "../systems/AudioSystem.h"
#include "../systems/SaveSystem.h"
#include <SFML/Graphics.hpp>


struct RoomID;
class Game {
    private:
    PlayerSystem playerSystem;
    WorldSystem worldSystem;

    public:
    void init();
    void update(float dt, sf::Vector2f screenSize);
    void render(sf::RenderWindow& window);

};
#endif //GAME_H
