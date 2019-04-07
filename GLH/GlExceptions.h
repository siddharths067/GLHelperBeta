#ifndef _GL_EXCEPTIONS_CLASS_
#define _GL_EXCEPTIONS_CLASS_

#include <exception>
#include <string>

class GlHelperException: public std::exception{
public:
    virtual const char* what() const throw(){
        return this->msg.c_str();    
    }

protected:

    std::string msg;
};

class GlContextFailedToInitializeException: public GlHelperException{

public:
    GlContextFailedToInitializeException(const char *filename, int line);
};

class GladFailedToLoadException: public GlHelperException{
public:
    GladFailedToLoadException(const char *filename, int line);
};

class GLSLFailedToLoadException: public GlHelperException{
public:
    GLSLFailedToLoadException(const char *filename, int line, const char *msg);
};

class GLSLShaderProgramLinkFailedException: public GlHelperException{
public:
    GLSLShaderProgramLinkFailedException(const char *filename, int line, const char *msg);
};

#endif