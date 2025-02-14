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
        bool visible = false;
        Cube(glm::vec3 pos);
        void DrawCube(Engine::Color color, float rotation);
};





#endif