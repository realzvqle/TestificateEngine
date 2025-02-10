#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED




#include "engine.h"



class Window {
    private:
        GLFWwindow* window = NULL;
    public:
        int InitWindow(int width, int height, const char* title);
        void WindowSwap();
        void ClearBackground(float red, float green, float blue, float alpha);
        int WindowShouldClose();
        bool IsKeyPressed(int key);
        void CleanUp();
    };

#endif