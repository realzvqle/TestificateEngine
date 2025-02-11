#include "engine/cube.hpp"
#include "engine/internals.hpp"
#include "engine/window.hpp"
#include "game/terrain.hpp"
#include "game/control.hpp"
#include <cstdio>
int main(){
    Window::InitWindow(1600, 900, "Testificate");
    Window::LockMouse();
    Cube cube;
    
    while(!Window::WindowShouldClose()){
        Window::ClearBackground(0, 0, 0, 0);
        Control();
        ImGui::NewFrame();
        ImGui::Begin("Testificate");
        std::printf("%f\n", Window::ReturnMouseX());
        //ImGui::Text("%d fps", Engine::GetFPS());
        Window::SetWindowTitle("Testificate Engine - %d fps", Engine::GetFPS());
        bool isClicked = ImGui::Button("Set Wired Mode?", {120, 45});
        if(isClicked) Engine::SetWiredMode();
        ImGui::End();
        ImGui::Render();
        //cube.DrawCube(Engine::RGB(1.0, 1.0, 1.0, 1.0), glm::vec3(0.5, 0.5, 0.5), 0);
        DrawTerrain();
        Window::WindowSwap();
    }
    Window::CleanUp();
}
