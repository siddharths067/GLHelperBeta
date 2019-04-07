#include <glad/glad.h>
#include "../GlContext.h"
#include "../GlExceptions.h"

GlContext::GlContext(std::string title, int height, int width, GLFWmonitor *monitor, GLFWwindow *share){
    this->title = title;
    this->height = height;
    this->width = width;
    this->monitor = NULL;
    this->share = NULL;

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);


}

void GlContext::initializeWindow(GLFWmonitor *monitor, GLFWwindow *share){
    this->monitor = monitor;
    this->share = share;

    this->window = glfwCreateWindow(800, 600, this->title.c_str(), this->monitor, this->share);

    if(this->window == NULL){
        throw new GlContextFailedToInitializeException(__FILE__, __LINE__);
    }
    this->setCurrentContext();
}

void GlContext::setCurrentContext(){
    glfwMakeContextCurrent(this->window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        throw new GladFailedToLoadException(__FILE__, __LINE__);
    }   
}

void GlContext::setViewPort(int x, int y, int sizex, int sizey){
    glViewport(x, y, sizex, sizey);
}


void GlContext::setFrameBufferSizeCallback(void (*framebuffer_size_callback)(GLFWwindow*, int, int)){
    this->framebuffer_size_callback = framebuffer_size_callback;
    glfwSetFramebufferSizeCallback(this->window, this->framebuffer_size_callback);
}


void GlContext::setEventLoop(void (*event_loop_callback)()){
    this->event_loop_callback = event_loop_callback;
}


void GlContext::setProcessInputCallback(void (*process_input_callback)(GLFWwindow *)){
    this->process_input_callback = process_input_callback;
}

void GlContext::runEventLoop(){
    while(!glfwWindowShouldClose(this->window)){
        this->process_input_callback(this->window);

        this->event_loop_callback();
        
        glfwSwapBuffers(this->window);
        glfwPollEvents();
    }
}

void GlContext::terminateContext(){
    glfwTerminate();
}