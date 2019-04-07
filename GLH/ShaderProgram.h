#ifndef _SHADER_PROGRAM_CLASS_
#define _SHADER_PROGRAM_CLASS_

#include "Shader.h"
#include <initializer_list>
#include <vector>

class ShaderProgram{
    unsigned int shaderProgramObject;
    char *infoLog;
    int linkSuccess, infoLogLength;

    void linkShaderProgram();
public:
    ShaderProgram();
    ShaderProgram(Shader shader, bool deleteOnSuccess = false);
    ShaderProgram(std::initializer_list<Shader> shaderList, bool deleteOnSuccess = false);
    ShaderProgram(std::vector<Shader> shaderVector, bool deleteOnSuccess = false);



    void useProgram();
};

#endif