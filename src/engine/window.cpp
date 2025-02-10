#include "window.hpp"
#include "engine.h"


namespace Window {

    GLFWwindow* window = NULL;

    void SizeCallback(GLFWwindow* window, int width, int height){
        glViewport(0, 0, width, height);
    }
    int InitWindow(int width, int height, const char* title){
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        window = glfwCreateWindow(1600, 900, "TESTIFICATE", NULL, NULL);
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
        //glfwSetWindowUserPointer(window, this);
        glfwSetFramebufferSizeCallback(window, SizeCallback);
        IMGUI_CHECKVERSION();
    
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        ImGui::StyleColorsDark();
        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init("#version 330");
        glEnable(GL_DEPTH_TEST);  
        return 0;
    }
    
    void WindowSwap(){
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    void ClearBackground(float red, float green, float blue, float alpha){
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(red, green, blue, alpha);
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
    }
    
    int WindowShouldClose(){
        return glfwWindowShouldClose(window);
    }
    
    void CleanUp(){
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
        glfwTerminate();
    }
    
    bool IsKeyPressed(int key){
        if(glfwGetKey(window, key)) return true;
        else return false;
    }
}


