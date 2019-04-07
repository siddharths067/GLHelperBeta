#include <GLFW/glfw3.h>
#include "GLH/GlContext.h"
#include <iostream>

// Execution Command
//  g++ 1.cpp GLH/src/GlContext.cpp GLH/src/GlExceptions.cpp -o 1 -lglfw -lGL -lX11 -lpthread -lXrandr  -ldl -fpermissive


void framebuffer_size_callback(GLFWwindow *window, int width, int height){
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void eventLoop(){
     glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
     glClear(GL_COLOR_BUFFER_BIT);
}


int main(int argc, char **argv){

    std::string title = "Hello World";
    GlContext context(title, 800, 600);
    context.initializeWindow();
    context.setViewPort(0, 0, 800, 600);
    context.setFrameBufferSizeCallback(framebuffer_size_callback);

    context.setProcessInputCallback(processInput);
    context.setEventLoop(eventLoop);
    context.runEventLoop();
    context.terminateContext();
    
    return 0;
}