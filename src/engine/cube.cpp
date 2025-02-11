#include "cube.hpp"
#include "camera.hpp"
#include "engine.h"
#include "fileio.hpp"
#include "shader.hpp"
#include "internals.hpp"


Cube::Cube(){
    float half = 0.3f / 2;
    float vertices[] = {
        -half, -half, -half,  
         half, -half, -half,  
         half,  half, -half,  
         half,  half, -half,  
        -half,  half, -half,  
        -half, -half, -half,  
    
        -half, -half,  half,  
         half, -half,  half,  
         half,  half,  half,  
         half,  half,  half,  
        -half,  half,  half,  
        -half, -half,  half,  
    
        -half,  half,  half,  
        -half,  half, -half,  
        -half, -half, -half,  
        -half, -half, -half,  
        -half, -half,  half,  
        -half,  half,  half,  
    
         half,  half,  half,  
         half,  half, -half,  
         half, -half, -half,  
         half, -half, -half,  
         half, -half,  half,  
         half,  half,  half,  
    
        -half, -half, -half,  
         half, -half, -half,  
         half, -half,  half,  
         half, -half,  half,  
        -half, -half,  half,  
        -half, -half, -half,  
    
        -half,  half, -half,  
         half,  half, -half,  
         half,  half,  half,  
         half,  half,  half,  
        -half,  half,  half,  
        -half,  half, -half  
    };

    this->indices[0] = 0;
    this->indices[1] = 1;
    this->indices[2] = 3;
    this->indices[3] = 1;
    this->indices[4] = 2;
    this->indices[5] = 3;
    
    
    glGenVertexArrays(1, &this->VAO);
    glBindVertexArray(this->VAO);
    
    glGenBuffers(1, &this->VBO);
    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &this->EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(this->indices), this->indices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);

    
    std::string vertexsrc = FileIO::ReadFile("glsl/vertex.glsl");
    std::string fragsrc = FileIO::ReadFile("glsl/fragment.glsl");
    unsigned int vertexobj = Shader::CompileShader(vertexsrc, Shader::VERTEX);
    unsigned int fragobj = Shader::CompileShader(fragsrc, Shader::FRAGMENT);
    this->program = Shader::LinkShaders(vertexobj, fragobj);

    glDeleteShader(vertexobj);
    glDeleteShader(fragobj);  

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0); 
    glBindVertexArray(0);
}


void Cube::DrawCube(Engine::Color color, glm::vec3 pos, float rotation){
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, pos) * glm::rotate(model, glm::radians(rotation), glm::vec3(0.5f, 1.0f, 0.0f));  
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

    glBindVertexArray(this->VAO);
    //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glDrawArrays(GL_TRIANGLES, 0, 36);

    //glBindVertexArray(0);
}


