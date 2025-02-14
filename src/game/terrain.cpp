#include "terrain.hpp"
#include "../engine/cube.hpp"



std::vector<Cube> cubes;

void DrawTerrain(){
    std::vector<int> toRemove; 
    static bool init = false;
    bool shouldraw = true;
    if(init == false){    
        cubes.emplace_back();
        init = true;
    }
    static float time = glfwGetTime();
    float in = 0;
    for (size_t i = 0; i < cubes.size(); ++i) {
        cubes[i].DrawCube(Engine::RGB(0.8f, 0.9f, 0.8f, 1.0f), glm::vec3(0.2 + in, 0.2, 0.2), in * 100);
        in += 0.5f;
        std::printf("%f\n", Engine::GetDeltaTime());
    }
    for (int i : toRemove) {
        cubes.erase(cubes.begin() + i);
    }
}


