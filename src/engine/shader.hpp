#ifndef SHADER_HPP_INCLUDED
#define SHADER_HPP_INCLUDED




#include "engine.h"








namespace Shader {
    typedef enum _ShaderType {
        VERTEX,
        FRAGMENT
    } ShaderType;
    unsigned int CompileShader(std::string source, ShaderType type);
    unsigned int LinkShaders(unsigned int fragshader, unsigned int vertshader);
}










#endif