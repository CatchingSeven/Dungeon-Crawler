//
// Created by maxhe on 11/29/2025.
//
#include "../../include/world/ProceduralGenerator.h"
int ProceduralGenerator::randomNumber(int min, int max) {
    return rand() % (max - min) + min;
}

void ProceduralGenerator::generateGenericRoom(int width, int height, int* level) {
    int min = 25, max = 40;
    for (int y = 0; y < height; y++) {

        for (int x = 0; x < width; x++) {

            if (x == 0 || y == 0 || x == width - 1 || y == height - 1) {
                level[y * width + x] = 0; // outer edges
            } else {
                level[y * width + x] = 25; // inner tiles
            }





        }
    }
}