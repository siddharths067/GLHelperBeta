#include "../GlExceptions.h"

GlContextFailedToInitializeException::GlContextFailedToInitializeException(const char *filename, int line){
    this->msg = (std::string("Failed to initialize GL Context") + 
        std::string(filename) + std::string(" at line ") +
        std::to_string(line));
}

GladFailedToLoadException::GladFailedToLoadException(const char *filename, int line){
    this->msg = (std::string("Failed to load GLAD, make sure you have built glad.c and GLAD headers are included") + 
        std::string(filename) + std::string(" at line ") +
        std::to_string(line));
}

GLSLFailedToLoadException::GLSLFailedToLoadException(const char *filename, int line, const char *msg){
    this->msg = (std::string("Failed to load and compile GLSL shader ") + 
        std::string(filename) + std::string(" at line ") +
        std::to_string(line) + std::string("\n \t") + 
        std::string(msg));
}

GLSLShaderProgramLinkFailedException::GLSLShaderProgramLinkFailedException(const char *filename, int line, const char *msg){
    this->msg = (std::string("Failed LINK GLSL program ") + 
        std::string(filename) + std::string(" at line ") +
        std::to_string(line) + std::string("\n \t") + 
        std::string(msg));
}