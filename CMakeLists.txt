cmake_minimum_required(VERSION 3.30)
project(Dungeon_Crawler)

set(CMAKE_CXX_STANDARD 17)
set(SFML_DIR "C:/Libraries/SFML-2.6.2/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
add_executable(Dungeon_Crawler src/main.cpp)
target_link_libraries(Dungeon_Crawler sfml-graphics sfml-window sfml-system)






