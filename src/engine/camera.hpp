#ifndef CAMERA_HPP_INCLUDED
#define CAMERA_HPP_INCLUDED






#include "engine.h"


namespace Camera {
    glm::mat4 ReturnCamera();
    void SetCameraLocation(float x, float y, float z);
    void SetCameraX(float x);
    void SetCameraY(float y);
    void SetCameraZ(float z);
}



#endif