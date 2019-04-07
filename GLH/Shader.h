#ifndef _SHADER_CLASS_
#define _SHADER_CLASS_

#include <string>
#include <fstream>
#include <glad/glad.h>

class Shader{
    unsigned int shaderObject;
    const char *sourcePath;
    const char *shaderSource;
    char *infoLog;
    int compileSuccess, infoLogLength;


    void compileShader(std::string shaderSource);
public:
    Shader(const char *sourcePath, GLenum type);
    void deleteShader();
    unsigned int getShaderObject();
    ~Shader();
};
#endif