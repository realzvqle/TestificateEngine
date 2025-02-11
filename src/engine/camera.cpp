#include "camera.hpp"
#include "window.hpp"



namespace Camera {
    float camX = 1.0f;
    float camY = 1.0f;
    float camZ = 1.0f;
    glm::mat4 ReturnCamera(){
        const float radius = 10.0f;
        glm::mat4 view;
        view = glm::lookAt(glm::vec3(camX, camY, camZ), glm::vec3(Window::ReturnMouseX(), Window::ReturnMouseY(), 0.0), glm::vec3(0.0, 1.0, 0.0)); 
        return view; 
    }
    void SetCameraLocation(float x, float y, float z){
        camX = x;
        camY = y;
        camZ = z;
    }
    void SetCameraX(float x){
        camX += x;
    }
    void SetCameraY(float y){
        camY += y;
    }
    void SetCameraZ(float z){
        camZ += z;
    }
}