#ifndef INTERNALS_HPP_INCLUDED
#define INTERNALS_HPP_INCLUDED







#include "engine.h"


namespace Engine {
    typedef struct _Color {
        float r;
        float g;
        float b;
        float a;
    } Color;
    Color RGB(float red, float green, float blue, float alpha);
    void SetWiredMode();
    void CalculateFrameRate();
    int GetFPS();
    double GetDeltaTime();
}



#endif