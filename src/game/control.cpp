#include "control.hpp"





void Control(){
    if(Window::IsKeyPressed(GLFW_KEY_W)) Camera::SetCameraX(0.1f * (float)Engine::GetDeltaTime());
    if(Window::IsKeyPressed(GLFW_KEY_S)) Camera::SetCameraX(-0.1f * (float)Engine::GetDeltaTime());
    if(Window::IsKeyPressed(GLFW_KEY_D)) Camera::SetCameraZ(0.1f * (float)Engine::GetDeltaTime());
    if(Window::IsKeyPressed(GLFW_KEY_A)) Camera::SetCameraZ(-0.1f * (float)Engine::GetDeltaTime());
    if(Window::IsKeyPressed(GLFW_KEY_UP)) Camera::SetCameraY(0.1f * (float)Engine::GetDeltaTime());
    if(Window::IsKeyPressed(GLFW_KEY_DOWN)) Camera::SetCameraY(-0.1f * (float)Engine::GetDeltaTime());
}