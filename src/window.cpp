#include "window.hpp"




static inline void SizeCallback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}

int Window::InitWindow(int width, int height, const char* title){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    this->window = glfwCreateWindow(1600, 900, "TESTIFICATE", NULL, NULL);
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
    glfwSetWindowUserPointer(window, this);
    glfwSetFramebufferSizeCallback(window, SizeCallback);
    IMGUI_CHECKVERSION();

    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");
    
    return 0;
}

void Window::WindowSwap(){
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    glfwSwapBuffers(this->window);
    glfwPollEvents();
}

void Window::ClearBackground(float red, float green, float blue, float alpha){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(red, green, blue, alpha);
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
}

int Window::WindowShouldClose(){
    return glfwWindowShouldClose(this->window);
}

void Window::CleanUp(){
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwTerminate();
}