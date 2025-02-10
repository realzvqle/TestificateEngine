#include "engine/window.hpp"

int main(){
    Window window;
    window.InitWindow(1600, 900, "Testificate");
    while(!window.WindowShouldClose()){
        window.ClearBackground(0, 0, 0, 0);
        ImGui::NewFrame();
        ImGui::Begin("Testificate");
        ImGui::Text("Hello World!");
        ImGui::Button("idk", {90, 90});
        ImGui::End();
        ImGui::Render();
        window.WindowSwap();
    }
    window.CleanUp();
}