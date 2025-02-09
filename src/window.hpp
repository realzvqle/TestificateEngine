#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED




#include "superheader.h"



class Window {
    private:
        GLFWwindow* window = NULL;
    public:
        int InitWindow(int width, int height, const char* title);
        void WindowSwap();
        void ClearBackground(float red, float green, float blue, float alpha);
        int WindowShouldClose();
        void CleanUp();
    };

#endif