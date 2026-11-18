//
// Created by maxhe on 11/29/2025.
//

#ifndef PROCEDURALGENERATOR__H
#define PROCEDURALGENERATOR__H
#include "../world/DungeonLayout.h"
#include "../world/Room.h"
#include <random>
#include <vector>

class ProceduralGenerator {
    private:


    public:
    void generateGenericRoom(int width, int height, std::vector<int>& level);
    int randomNumber(int min, int max);


};
#endif //PROCEDURALGENERATOR__H
