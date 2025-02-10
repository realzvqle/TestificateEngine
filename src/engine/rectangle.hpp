#ifndef RECTANGLE_HPP_INCLUDED
#define RECTANGLE_HPP_INCLUDED








#include "engine.h"
#include "internals.hpp"


class Rectangle {
    private:
        float vertices[12];
        unsigned int indices[6];
        unsigned int VBO;
        unsigned int VAO;
        unsigned int EBO;
        unsigned int program;
    public:
        Rectangle();
        void DrawRectangle(Engine::Color color);
};





#endif