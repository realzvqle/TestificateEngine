#include "terrain.hpp"
#include "../engine/cube.hpp"



std::vector<Cube> cubes;

void DrawTerrain(){
    static float startX = -2.0f, startY = -2.0f, startZ = -2.0f; 
    static float posx = startX, posy = startY, posz = startZ;
    static bool init = false;
    if(init == false){
        for (float x = startX; x < 2.0f; x += 0.2f) {
            for (float z = startZ; z < 2.0f; z += 0.2f) {
                cubes.emplace_back(); 
            }
        }
        init = true;
    }

    for (auto& cube : cubes) {
        cube.DrawCube(Engine::RGB(0.5f, 0.5f, 0.5f, 1.0f), glm::vec3(posx * 1.5f, 0.5, posz * 1.5f), 0);
        posz += 0.2f;
        if (posz > 2.0f) { posz = startZ; posx += 0.2f; }
    }

    posx = 0.0f;
    posz = 0.0f;
}


