#include "terrain.hpp"
#include "../engine/cube.hpp"



std::vector<Cube> cubes;

void DrawTerrain(){
    static float startX = -2.0f, startZ = -2.0f; 
    static float i = startX, zz = startZ;
    static bool init = false;
    if(init == false){
        for (float x = startX; x < 7.0f; x += 0.2f) {
            for (float z = startZ; z < 7.0f; z += 0.2f) {
                cubes.emplace_back(); 
            }
        }
        init = true;
    }

    for (auto& cube : cubes) {
        cube.DrawCube(Engine::RGB(0.5f, 0.5f, 0.5f, 1.0f), glm::vec3(i * 1.5f, -0.5f, zz * 1.5f), 0);
        zz += 0.2f;
        if (zz > 7.0f) { zz = startZ; i += 0.2f; }
    }

    i = 0.0f;
    zz = 0.0f;

}


