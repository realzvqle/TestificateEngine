#include "terrain.hpp"
#include "../engine/cube.hpp"



std::vector<Cube> cubes;


bool grid[11][11][31] = {false};  

bool isSurrounded(int x, int y, int z) {
    if (x <= 0 || x >= 10 || y <= 0 || y >= 10 || z <= 0 || z >= 30) {
        return false; 
    }
    
    return grid[x-1][y][z] && grid[x+1][y][z] &&
           grid[x][y-1][z] && grid[x][y+1][z] &&
           grid[x][y][z-1] && grid[x][y][z+1];
}

void DrawTerrain() {
    static bool init = false;
    if (!init) {
        float x = 0, y = 0.2f, z = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 30; k++) {
                    grid[i][j][k] = true; 
                }
            }
        }
        x = 0, y = 0.2f, z = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 30; k++) {
                    float x = i * 0.3f;
                    float z = j * 0.3f;
                    float y = k * 0.4f;
                    bool visible;
                    if (!isSurrounded(i, j, k)) {
                        cubes.emplace_back(glm::vec3(x, y, z));
                    } 
                }
            }
        }

        init = true;
    }

    // Render all visible cubes
    for (Cube& cube : cubes) {
        cube.DrawCube(Engine::RGB(0.6f, 0.9f, 0.8f, 1.0f), 0);
    }
}



