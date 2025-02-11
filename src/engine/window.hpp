#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED




#include "engine.h"


namespace Window {
    int InitWindow(int width, int height, const char* title);
    void WindowSwap();
    void ClearBackground(float red, float green, float blue, float alpha);
    int WindowShouldClose();
    void CleanUp();
    bool IsKeyPressed(int key);
    void SetWindowTitle(const char* format, ...);
    void LockMouse();
    void UnlockMouse();
    double ReturnMouseX();
    double ReturnMouseY();
}

#endif