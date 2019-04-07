#ifndef _GL_CONTEXT_CLASS_
#define _GL_CONTEXT_CLASS_

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

class GlContext{
    GLFWwindow *window, *share;
    GLFWmonitor *monitor;
    int width, height;
    std::string title;

    void (*framebuffer_size_callback)(GLFWwindow*, int, int);
    void (*process_input_callback)(GLFWwindow*);
    void (*event_loop_callback)();

public:

    GlContext(std::string title, int width, int height, GLFWmonitor *monitor = NULL, GLFWwindow *window = NULL);
        

    void initializeWindow(GLFWmonitor *monitor = NULL, GLFWwindow *window = NULL);
    void setCurrentContext();
    void setViewPort(int x, int y, int sizex, int sizey);
    void setFrameBufferSizeCallback(void (*framebuffer_size_callback)(GLFWwindow*, int, int));
    void setEventLoop(void (*event_loop_callback)());
    void runEventLoop();
    void setProcessInputCallback(void (*process_input_callback)(GLFWwindow *));
    void terminateContext();

};

#endif