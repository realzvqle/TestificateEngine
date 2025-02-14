#include "cube.hpp"
#include "camera.hpp"
#include "engine.h"
#include "fileio.hpp"
#include "shader.hpp"
#include "internals.hpp"

// namespace Shader {
//     extern unsigned int program;
// }

static bool setup = false;
static unsigned int VBO;
static unsigned int VAO;
Cube::Cube(glm::vec3 pos){
    float half = 0.3f / 2;
    float vertices[] = {
        -half, -half,  half,  
        half, -half,  half,  
        half,  half,  half,  
        half,  half,  half,  
        -half,  half,  half,  
        -half, -half,  half,  

        half, -half, -half,  
        -half, -half, -half,  
        -half,  half, -half,  
        -half,  half, -half,  
        half,  half, -half,  
        half, -half, -half,  

        -half, -half, -half,  
        -half, -half,  half,  
        -half,  half,  half,  
        -half,  half,  half,  
        -half,  half, -half,  
        -half, -half, -half,  

        half, -half,  half,  
        half, -half, -half,  
        half,  half, -half,  
        half,  half, -half,  
        half,  half,  half,  
        half, -half,  half,  

        -half, -half, -half,  
        half, -half, -half,  
        half, -half,  half,  
        half, -half,  half,  
        -half, -half,  half,  
        -half, -half, -half,  

        -half,  half,  half,  
        half,  half,  half,  
        half,  half, -half,  
        half,  half, -half,  
        -half,  half, -half,  
        -half,  half,  half  
    };
    
   
    if(!setup){
        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);
        
        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        setup = true;
        std::printf("Setup!\n");
    }
    this->pos = pos;
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
 

    this->program = Shader::ReturnShaderProgram();

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0); 
    glBindVertexArray(0);
}


void Cube::DrawCube(Engine::Color color, float rotation){
    //if(visible != true) return;
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(glm::mat4(1.0f), this->pos);
    model = glm::rotate(model, glm::radians(rotation), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::scale(model, glm::vec3(1.0f, 1.4f, 1.0f));
    glm::mat4 view = Camera::ReturnCamera();
    // glm::mat4 view = glm::mat4(1.0f);
    // view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
    glm::mat4 projection;
    projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
    int colorLocation = glGetUniformLocation(this->program, "ourColor");
    int modellocation = glGetUniformLocation(this->program, "model");
    int viewlocation = glGetUniformLocation(this->program, "view");
    int projectionlocation = glGetUniformLocation(this->program, "projection");

    glUseProgram(this->program);
    glUniform4f(colorLocation, color.r, color.g, color.b, color.a);
    glUniformMatrix4fv(modellocation, 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(viewlocation, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(projectionlocation, 1, GL_FALSE, glm::value_ptr(projection));

    glBindVertexArray(VAO);
    //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    //glFrontFace(GL_CCW);
    //glBindVertexArray(0);
}


