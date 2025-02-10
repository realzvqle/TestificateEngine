#include "triangle.hpp"
#include "engine.h"
#include "fileio.hpp"
#include "shader.hpp"



Triangle::Triangle(){
    this->vertices[0] = -0.5f; // point 1 - x
    this->vertices[1] = -0.5f; // point 1 - y
    this->vertices[2] = 0.0f;  // point 1 - z
    this->vertices[3] = 0.5f;  // point 2 - x
    this->vertices[4] = -0.5f; // point 2 - y
    this->vertices[5] = 0.0f;  // point 2 - z
    this->vertices[6] = 0.0f;  // point 3 - x
    this->vertices[7] = 0.5f;  // point 3 - y
    this->vertices[8] = 0.0f;  // point 3 - z
    glGenVertexArrays(1, &this->VAO);
    glBindVertexArray(this->VAO);
    glGenBuffers(1, &this->VBO);
    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(this->vertices), this->vertices, GL_STATIC_DRAW);
    std::string vertexsrc = FileIO::ReadFile("glsl/vertex.glsl");
    std::string fragsrc = FileIO::ReadFile("glsl/fragment.glsl");
    unsigned int vertexobj = Shader::CompileShader(vertexsrc, Shader::VERTEX);
    unsigned int fragobj = Shader::CompileShader(fragsrc, Shader::FRAGMENT);
    this->program = Shader::LinkShaders(vertexobj, fragobj);

    glDeleteShader(vertexobj);
    glDeleteShader(fragobj);  

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0); 
}


void Triangle::DrawTriangle(){
    glUseProgram(this->program);
    glBindVertexArray(this->VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}