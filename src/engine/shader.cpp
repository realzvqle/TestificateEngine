#include "shader.hpp"
#include "engine.h"



namespace Shader {
    unsigned int CompileShader(std::string source, ShaderType type){
        unsigned int shader;
        const char* shadersrc = source.c_str();
        if(type == FRAGMENT) shader = glCreateShader(GL_FRAGMENT_SHADER);
        else if(type == VERTEX) shader = glCreateShader(GL_VERTEX_SHADER);
        else return NULL;
        glShaderSource(shader, 1, &shadersrc, NULL);
        glCompileShader(shader);
        int success;
        char infoLog[512];
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if(!success){
            glGetShaderInfoLog(shader, 512, NULL, infoLog);
            std::printf("Error: %s\n", infoLog);
            return 0;
        } else return shader;
    }

    unsigned int LinkShaders(unsigned int fragshader, unsigned int vertshader){
        unsigned int program;
        program = glCreateProgram();

        glAttachShader(program, vertshader);
        glAttachShader(program, fragshader);
        glLinkProgram(program);
        
        int success;
        char infoLog[512];
        glGetProgramiv(program, GL_LINK_STATUS, &success);
        if(!success) {
            glGetProgramInfoLog(program, 512, NULL, infoLog);
            std::printf("Error: %s\n", infoLog);
            return 0;
        } else return program;
    }

}