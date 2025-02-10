#include "engine/internals.hpp"
#include "engine/rectangle.hpp"
#include "engine/window.hpp"

int main(){
    Window window;
    window.InitWindow(1600, 900, "Testificate");
    Rectangle rect;
    float red = 1.0f;
    float green = 1.0f;
    float blue = 1.0f;
    while(!window.WindowShouldClose()){
        window.ClearBackground(0, 0, 0, 0);
        ImGui::NewFrame();
        ImGui::Begin("Testificate");
        ImGui::Text("Hello World!");
        bool isClicked = ImGui::Button("Set Wired Mode?", {120, 45});
        if(isClicked) Engine::SetWiredMode();
        ImGui::SliderFloat("Red", &red, 0.0f, 1.0f);
        ImGui::SliderFloat("Blue", &blue, 0.0f, 1.0f);
        ImGui::SliderFloat("Green", &green, 0.0f, 1.0f);
        ImGui::End();
        ImGui::Render();
        rect.DrawRectangle(Engine::RGB(red, green, blue, 1.0f));
        window.WindowSwap();
    }
    window.CleanUp();
}
