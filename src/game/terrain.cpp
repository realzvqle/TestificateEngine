#include "terrain.hpp"
#include "../engine/cube.hpp"



std::vector<Cube> cubes;

void DrawTerrain(){
    std::vector<int> toRemove; 
    static float startX = -2.0f, startY = -2.0f, startZ = -2.0f; 
    static float posx = startX, posy = startY, posz = startZ;
    static bool init = false;
    bool shouldraw = true;
    if(init == false){
        for (float x = startX; x < 1.1f; x += 0.2f) {
            for (float z = startZ; z < 1.1f; z += 0.2f) {
                cubes.emplace_back(); 
            }
        }
        init = true;
    }
    static float time = glfwGetTime();
    for (size_t i = 0; i < cubes.size(); ++i) {
        // if(glfwGetTime() - time >= 0.1){
        //     toRemove.push_back(i);
        //     time = glfwGetTime();
        // }
        if(shouldraw == true) cubes[i].DrawCube(Engine::RGB(0.5f, 0.9f, 0.8f, 1.0f), glm::vec3(posx * 1.5f, 0.5, posz * 1.5f), 0);
        posz += 0.2f;
        if (posz > 1.1f) {posz = startZ; posx += 0.2f;}
    }
    for (int i : toRemove) {
        cubes.erase(cubes.begin() + i);
    }
    posx = 0.0f;
    posz = 0.0f;
}


