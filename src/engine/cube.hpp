#ifndef CUBE_HPP_INCLUDED
#define CUBE_HPP_INCLUDED








#include "engine.h"
#include "internals.hpp"

class Cube {
    private:
        unsigned int indices[6];
        
        unsigned int program;  
    public:
        glm::vec3 pos;
        Cube();
        void DrawCube(Engine::Color color, glm::vec3 pos, float rotation);
};





#endif