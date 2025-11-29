cmake_minimum_required(VERSION 3.30)
project(Dungeon_Crawler)

set(CMAKE_CXX_STANDARD 17)
set(SFML_DIR "C:/Libraries/SFML-2.6.2/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
add_executable(Dungeon_Crawler
        src/main.cpp

        # core
        src/core/GameApp.cpp
        src/core/Game.cpp


        # entities
        src/entities/Player.cpp
        src/entities/Enemy.cpp
        src/entities/BossEnemy.cpp
        src/entities/Projectile.cpp

        # items
        src/items/Item.cpp
        src/items/Weapon.cpp
        src/items/Armor.cpp
        src/items/Consumable.cpp
        src/items/KeyItem.cpp
        src/items/MagicItem.cpp
        src/items/Inventory.cpp
        src/items/Hotbar.cpp
        src/items/ItemInstance.cpp

        # world
        src/world/TileMap.cpp
        src/world/Room.cpp
        src/world/DungeonLayout.cpp
        src/world/ProceduralGenerator.cpp


        # systems
        src/systems/WorldSystem.cpp
        src/systems/PlayerSystem.cpp
        src/systems/EnemySystem.cpp
        src/systems/CombatSystem.cpp
        src/systems/ItemSystem.cpp
        src/systems/UISystem.cpp
        src/systems/AudioSystem.cpp
        src/systems/SaveSystem.cpp

        # ui
        src/ui/UIElement.cpp
        src/ui/HealthBar.cpp
        src/ui/ManaBar.cpp
        src/ui/HotbarUI.cpp
        src/ui/InventoryUI.cpp
        src/ui/MenuUI.cpp
        src/ui/MainMenuUI.cpp
        src/ui/PauseMenuUI.cpp
        src/ui/DeathScreenUI.cpp
        src/ui/TextRenderer.cpp

        # audio
        src/audio/MusicPlayer.cpp
        src/audio/SoundEffectPlayer.cpp

        # save
        src/save/SaveFile.cpp
        src/save/Serializer.cpp

        # utils
        src/utils/Hitbox.cpp
        src/utils/DamageCalculator.cpp
)

target_link_libraries(Dungeon_Crawler sfml-graphics sfml-window sfml-system)






