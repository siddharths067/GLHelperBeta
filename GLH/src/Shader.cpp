#include "../Shader.h"
#include "../GlExceptions.h"

Shader::Shader(const char *sourcePath, GLenum type){
    shaderObject = glCreateShader(type);
    std::ifstream inputFile(sourcePath);
    std::string tempSource((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
    this->shaderSource = tempSource.c_str();
    this->compileShader(this->shaderSource);
}

void Shader::compileShader(std::string shaderSource){
    glShaderSource(this->shaderObject, 1, &this->shaderSource, NULL);
    glCompileShader(this->shaderObject);
    glGetShaderiv(this->shaderObject, GL_INFO_LOG_LENGTH, &this->infoLogLength);
    this->infoLog = new char[this->infoLogLength];
    glGetShaderiv(this->shaderObject, GL_COMPILE_STATUS, &this->compileSuccess);
    if(!(this->compileSuccess)){
        glGetShaderInfoLog(this->shaderObject, this->infoLogLength, NULL, this->infoLog);
        throw GLSLFailedToLoadException(__FILE__, __LINE__, this->infoLog);
    }
}

void Shader::deleteShader(){
    glDeleteShader(this->shaderObject);
}

unsigned int Shader::getShaderObject(){
    return this->shaderObject;
}

Shader::~Shader(){
    //glDeleteShader(this->shaderObject);
}