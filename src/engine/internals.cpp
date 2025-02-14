#include "internals.hpp"
#include "engine.h"


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
    // void SetCulled(){
    //     static bool isCulled = false;
    //     if(isCulled == false) isCulled = true;
    //     else isCulled = false;

    //     if(isCulled == true){
    //         glEnable(GL_CULL_FACE);
    //         glCullFace(GL_FRONT);
    //         glFrontFace(GL_CW);
    //         glDepthFunc(GL_LESS);

    //     } 
    //     else glDisable(GL_CULL_FACE);
    // }
    
    void CalculateFrameRate() {
        static float lasttime = glfwGetTime();
        float currenttime = glfwGetTime();

        const float elapsedTime = currenttime - lasttime;
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
    static double prevtime;
    static double curtime;
    void CalculateDeltaTime(){ 
        prevtime = curtime;
        curtime = glfwGetTime();
    }
    
    double GetDeltaTime(){
        return curtime - prevtime;
    }
}