#include "internals.hpp"
#include "engine.h"
#include <chrono>


namespace Engine {
    Color RGB(float red, float green, float blue, float alpha){
        Color color = {red, green, blue, alpha};
        return color;
    }

    void SetWiredMode(){
        static bool isWired = false;
        if(isWired == false) isWired = true;
        else isWired = false;

        if(isWired == true) glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        else glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
    int fpscount = 0;
    int fps = 0;
    std::chrono::time_point<std::chrono::steady_clock> lastTime = std::chrono::steady_clock::now();
    std::chrono::duration<double> deltaTime = std::chrono::duration<double>::zero();

    void CalculateFrameRate() {
        auto currentTime = std::chrono::steady_clock::now();
        deltaTime = currentTime - lastTime;
        ++fpscount;
        if (deltaTime.count() >= 1.0) {
            lastTime = currentTime;
            fps = fpscount;
            fpscount = 0;
        }
    }

    double GetDeltaTime() {
        return deltaTime.count();  
    }

    int GetFPS() {
        return fps;
    }
}