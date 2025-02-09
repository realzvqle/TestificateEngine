#include "../include/glad/glad.h"
#include "../include/GLFW/glfw3.h"
#include <cstddef>
#include <cstdio>
#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_glfw.h"
#include "../imgui/imgui_impl_opengl3.h"

void SizeCallback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}

int main(){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* window = glfwCreateWindow(1600, 900, "TESTIFICATE", NULL, NULL);
    if(!window){
        std::printf("Failed Creating the Window");
        return -1;  
    }
    glfwMakeContextCurrent(window);
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::printf("Failed Loading OpenGL");
        return -1;  
    }
    glViewport(0, 0, 1600, 900);
    glfwSetFramebufferSizeCallback(window, SizeCallback);
    IMGUI_CHECKVERSION();

    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");
    float red = 0;
    float green = 0;
    float blue = 0;
    float alpha = 0;
    while(!glfwWindowShouldClose(window)){
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(red, green, blue, alpha);
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        ImGui::Begin("Testificate");
        ImGui::Text("HTestificateello");
        ImGui::SliderFloat("Red", &red, 0, 1);
        ImGui::SliderFloat("Green", &green, 0, 1);
        ImGui::SliderFloat("Blue", &blue, 0, 1);
        ImGui::SliderFloat("Alpha", &alpha, 0, 1);
        ImGui::End();
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}