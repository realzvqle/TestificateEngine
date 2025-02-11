#include "internals.hpp"
#include "engine.h"
#include <chrono>


namespace Engine {
    static int fpscount = 0;
    static int fps = 0; 
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
    
    void CalculateFrameRate() {
        static float lasttime = glfwGetTime();
        float currenttime = glfwGetTime();

        const auto elapsedTime = currenttime - lasttime;
        ++fpscount;

        if (elapsedTime > 1) {
            lasttime = currenttime;
            fps = fpscount;
            fpscount = 0;
        }
    }

    int GetFPS(){
        return fps;
    }
    double GetDeltaTime(){ // deltatime
        return 1.1; // don't have an implementation
    }
}