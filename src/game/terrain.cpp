#include "terrain.hpp"
#include "../engine/cube.hpp"



std::vector<Cube> cubes;


int grid[] = {
    0, // index 0 is the information, thats why it isn't being used
    1, 1, 1, 1, 1,
    0, 0, 0, 0, 1,
    0, 0, 1, 1, 0,
    0, 1, 0, 0, 0,
    1, 1, 1, 1, 1 
};

void DrawTerrain() {
    static bool init = false;
    if (!init) {
        int size = sizeof(grid)/sizeof(grid[0]);
        int upscale = 0;
        int x = 0;
        for(int i = 0; i < size; i++){
            if(i == 0){
                std::printf("Rendering Chunk %d\n", grid[0]);
                continue;
            }
            if(grid[i] == 1) cubes.emplace_back(glm::vec3(x * 0.3, upscale * 0.4, 0.3));
            if(i % 5 == 0 && i != 0){
                upscale--;
                x = 0;
            }   
            else x++;
        }
        init = true;
    }

    for (Cube& cube : cubes) {
        cube.DrawCube(Engine::RGB(0.6f, 0.9f, 0.8f, 1.0f), 0);
    }
}



