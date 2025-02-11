#include "engine/camera.hpp"
#include "engine/cube.hpp"
#include "engine/internals.hpp"
#include "engine/rectangle.hpp"
#include "engine/window.hpp"
#include <vector>

int main(){
    Window::InitWindow(1600, 900, "Testificate");
    std::vector<Cube> cubes;
    cubes.emplace_back();
    cubes.emplace_back();
    cubes.emplace_back();
    cubes.emplace_back();
    cubes.emplace_back();
    //cubes.emplace_back(4.5);
    //cubes.emplace_back(2.0);
    //Cube cube(0.3);
    float red = 1.0f;
    float green = 1.0f;
    float blue = 1.0f;
    float x = 0.5f;
    float y = 0.5f;
    float z = 0.5f;
    float rotation = 90.0f;
    float i = 0.0f;
    while(!Window::WindowShouldClose()){
        Window::ClearBackground(0, 0, 0, 0);
        if(Window::IsKeyPressed(GLFW_KEY_W)) Camera::SetCameraX(0.001f);
        if(Window::IsKeyPressed(GLFW_KEY_S)) Camera::SetCameraX(-0.001f);
        if(Window::IsKeyPressed(GLFW_KEY_D)) Camera::SetCameraZ(0.001f);
        if(Window::IsKeyPressed(GLFW_KEY_A)) Camera::SetCameraZ(-0.001f);
        ImGui::NewFrame();
        ImGui::Begin("Testificate");
        bool isClicked = ImGui::Button("Set Wired Mode?", {120, 45});
        if(isClicked) Engine::SetWiredMode();
        ImGui::End();
        ImGui::Render();
        for (auto& cube : cubes) {
            cube.DrawCube(Engine::RGB(0.1f, 1.0f, 1.0f, 1.0f), glm::vec3(i, i, i), 0);
            i+=0.1f;
        }
        i = 0.0f;
        Window::WindowSwap();
    }
    Window::CleanUp();
}
