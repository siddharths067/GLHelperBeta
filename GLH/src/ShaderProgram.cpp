#include "../ShaderProgram.h"
#include "../GlExceptions.h"
#include <iostream>

ShaderProgram::ShaderProgram(){
    this->shaderProgramObject = glCreateProgram();
}

ShaderProgram::ShaderProgram(Shader shader, bool deleteOnSuccess):ShaderProgram(){
    glAttachShader(this->shaderProgramObject, shader.getShaderObject());
    this->linkShaderProgram();
    if(deleteOnSuccess)
        glDeleteShader(shader.getShaderObject());
}


ShaderProgram::ShaderProgram(std::vector<Shader> shaderVector, bool deleteOnSuccess):ShaderProgram(){
    for(std::vector<Shader>::iterator shaderItr = shaderVector.begin(); shaderItr != shaderVector.end(); shaderItr++){
        glAttachShader(this->shaderProgramObject, shaderItr->getShaderObject());
    }
    this->linkShaderProgram();
    if(deleteOnSuccess)
        for(std::vector<Shader>::iterator shaderItr = shaderVector.begin(); shaderItr != shaderVector.end(); shaderItr++){
            glDeleteShader(shaderItr->getShaderObject());
    }   
}

ShaderProgram::ShaderProgram(std::initializer_list<Shader> shaderList, bool deleteOnSuccess):
    ShaderProgram(std::vector<Shader>(shaderList.begin(), shaderList.end()), deleteOnSuccess){
}

void ShaderProgram::linkShaderProgram(){
    glLinkProgram(this->shaderProgramObject);
    glGetProgramiv(this->shaderProgramObject, GL_INFO_LOG_LENGTH, &this->infoLogLength);
    this->infoLog = new char[infoLogLength];
    this->infoLog[0] = '\0';
    glGetProgramiv(this->shaderProgramObject, GL_LINK_STATUS, &this->linkSuccess);
    if(!(this->linkSuccess)){
        std::cout<<this->infoLogLength<<" "<<this->infoLog<<std::endl;
        glGetProgramInfoLog(this->shaderProgramObject, this->infoLogLength, NULL, this->infoLog);
        throw GLSLShaderProgramLinkFailedException(__FILE__, __LINE__, this->infoLog);
    }
}
void ShaderProgram::useProgram(){
    glUseProgram(this->shaderProgramObject);
}