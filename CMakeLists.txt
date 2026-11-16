cmake_minimum_required(VERSION 3.30)
project(Dungeon_Crawler LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Build SFML 2 with the same compiler/runtime as the game. MSYS2 currently
# supplies SFML 3, whose API is incompatible with this codebase.
option(DUNGEON_USE_SYSTEM_SFML "Use an existing toolchain-compatible SFML 2 installation" OFF)
if(DUNGEON_USE_SYSTEM_SFML)
    find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)
else()
    include(FetchContent)
    set(SFML_BUILD_AUDIO OFF CACHE BOOL "" FORCE)
    set(SFML_BUILD_NETWORK OFF CACHE BOOL "" FORCE)
    set(SFML_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    set(SFML_BUILD_DOC OFF CACHE BOOL "" FORCE)
    set(SFML_USE_SYSTEM_DEPS ON CACHE BOOL "" FORCE)
    FetchContent_Declare(sfml
        URL https://github.com/SFML/SFML/archive/5383d2b3948f805af55c9f8a4587ac72ec5981d1.tar.gz
        URL_HASH SHA256=d10569c2b62809ac08fee6e5d7c403aca439eb36586332258c1a1279d0c1a669
    )
    FetchContent_MakeAvailable(sfml)
endif()
add_executable(Dungeon_Crawler
        src/main.cpp

        # core
        src/core/GameApp.cpp
        src/core/Game.cpp


        # entities
        src/entities/Entity.cpp
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
        include/enums/RoomState.h
        include/enums/TileType.h

)

target_link_libraries(Dungeon_Crawler sfml-graphics sfml-window sfml-system)
target_compile_definitions(Dungeon_Crawler PRIVATE
    DUNGEON_ASSET_DIR="${CMAKE_CURRENT_SOURCE_DIR}/assets"
)

if(WIN32)
    add_custom_command(TARGET Dungeon_Crawler POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_RUNTIME_DLLS:Dungeon_Crawler>
            $<TARGET_FILE_DIR:Dungeon_Crawler>
        COMMAND_EXPAND_LISTS
    )
endif()
