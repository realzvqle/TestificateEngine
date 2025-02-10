#ifndef TRIANGLE_HPP_INCLUDED
#define TRIANGLE_HPP_INCLUDED








#include "engine.h"



class Triangle {
    private:
        float vertices[9];
        unsigned int VBO;
        unsigned int VAO;
        unsigned int program;
    public:
        Triangle();
        void DrawTriangle();
};





#endif