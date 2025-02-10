#include "internals.hpp"
#include "engine.h"



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
}