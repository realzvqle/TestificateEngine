#include "control.hpp"





void Control(){
    if(Window::IsKeyPressed(GLFW_KEY_W)) Camera::SetCameraX(10.0f * Engine::GetDeltaTime());
    if(Window::IsKeyPressed(GLFW_KEY_S)) Camera::SetCameraX(-10.0f * Engine::GetDeltaTime());
    if(Window::IsKeyPressed(GLFW_KEY_D)) Camera::SetCameraZ(10.0f * Engine::GetDeltaTime());
    if(Window::IsKeyPressed(GLFW_KEY_A)) Camera::SetCameraZ(-10.0f * Engine::GetDeltaTime());
    if(Window::IsKeyPressed(GLFW_KEY_UP)) Camera::SetCameraY(10.0f * Engine::GetDeltaTime());
    if(Window::IsKeyPressed(GLFW_KEY_DOWN)) Camera::SetCameraY(-10.0f * Engine::GetDeltaTime());
    if(Window::IsKeyPressed(GLFW_KEY_ESCAPE)) Window::UnlockMouse();
    if(Window::IsKeyPressed(GLFW_KEY_ENTER)) Window::LockMouse();
}