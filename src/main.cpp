#include "engine/cube.hpp"
#include "engine/internals.hpp"
#include "engine/rectangle.hpp"
#include "engine/window.hpp"

int main(){
    Window::InitWindow(1600, 900, "Testificate");
    Cube cube(0.3);
    float red = 1.0f;
    float green = 1.0f;
    float blue = 1.0f;
    float x = 0.5f;
    float y = 0.5f;
    float z = 0.5f;
    float rotation = 90.0f;
    while(!Window::WindowShouldClose()){
        Window::ClearBackground(0, 0, 0, 0);
        ImGui::NewFrame();
        ImGui::Begin("Testificate");
        bool isClicked = ImGui::Button("Set Wired Mode?", {120, 45});
        if(isClicked) Engine::SetWiredMode();
        ImGui::Text("Color");
        ImGui::SliderFloat("Red", &red, 0.0f, 1.0f);
        ImGui::SliderFloat("Blue", &blue, 0.0f, 1.0f);
        ImGui::SliderFloat("Green", &green, 0.0f, 1.0f);
        ImGui::Text("Position");
        ImGui::SliderFloat("X", &x, -1.0f, 1.0f);
        ImGui::SliderFloat("Y", &y, -1.0f, 1.0f);
        ImGui::SliderFloat("Z", &z, -1.0f, 1.0f);
        ImGui::Text("Rotation");
        ImGui::SliderFloat("Rotation", &rotation, 0, 360.0f);
        ImGui::End();
        ImGui::Render();
        cube.DrawCube(Engine::RGB(red, green, blue, 1.0f), glm::vec3(x, y, z), rotation);
        Window::WindowSwap();
    }
    Window::CleanUp();
}
