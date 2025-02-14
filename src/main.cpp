#include "engine/cube.hpp"
#include "engine/internals.hpp"
#include "engine/window.hpp"
#include "game/terrain.hpp"
#include "game/control.hpp"
#include <cstdio>
int main(){
    Window::InitWindow(1600, 900, "Testificate");
    
    
    while(!Window::WindowShouldClose()){
        Window::ClearBackground(0, 0, 0, 0);
        Control();
        ImGui::NewFrame();
        ImGui::Begin("Testificate");
        Window::SetWindowTitle("Testificate Engine - %d fps", Engine::GetFPS());
        // imgui on the main file lets fycking gogoogogogo
        bool isClicked = ImGui::Button("Set Wired Mode?", {120, 45});
        if(isClicked) Engine::SetWiredMode();
        ImGui::End();
        ImGui::Render();
        DrawTerrain();
        Window::WindowSwap();
    }
    Window::CleanUp();
}
