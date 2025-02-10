#include "rectangle.hpp"
#include "engine.h"
#include "fileio.hpp"
#include "shader.hpp"
#include "internals.hpp"


Rectangle::Rectangle(){
    this->vertices[0] = 0.5f;
    this->vertices[1] = 0.5f;
    this->vertices[2] = 0.0f;  
    this->vertices[3] = 0.5f;  
    this->vertices[4] = -0.5f; 
    this->vertices[5] = 0.0f; 
    this->vertices[6] = -0.5f;  
    this->vertices[7] = -0.5f;  
    this->vertices[8] = 0.0f;  
    this->vertices[9] = -0.5f;
    this->vertices[10] = 0.5f;
    this->vertices[11] = 0.0f;

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
    glBufferData(GL_ARRAY_BUFFER, sizeof(this->vertices), this->vertices, GL_STATIC_DRAW);

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


void Rectangle::DrawRectangle(Engine::Color color){
    glm::mat4 trans = glm::mat4(1.0f);    
    trans = glm::rotate(trans, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
    trans = glm::scale(trans, glm::vec3(0.5,0.5,0.5));
    
    int colorLocation = glGetUniformLocation(this->program, "ourColor");
    int transformlocation = glGetUniformLocation(this->program, "transform");
    glUseProgram(this->program);
    glUniform4f(colorLocation, color.r, color.g, color.b, color.a);
    glUniformMatrix4fv(transformlocation, 1, GL_FALSE, glm::value_ptr(trans));
    glBindVertexArray(this->VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}