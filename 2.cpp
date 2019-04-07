#include "GLH/GlContext.h"
#include "GLH/GlExceptions.h"
#include "GLH/Shader.h"
#include "GLH/ShaderProgram.h"

#include <iostream>
void framebuffer_size_callback(GLFWwindow *window, int width, int height){
    glViewport(0, 0, width, height);
}

void process_input(GLFWwindow *window){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

unsigned int VBO, VAO;
void event_loop(){
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glClear(GL_COLOR_BUFFER_BIT);
}


float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
}; 




int main(int argc, char **argv){


    GlContext context("Drawing a Triangle", 800, 600);
    context.initializeWindow();
    context.setEventLoop(event_loop);
    context.setFrameBufferSizeCallback(framebuffer_size_callback);
    context.setProcessInputCallback(process_input);
    context.setViewPort(0, 0, 800, 600);


    try{
        Shader vertex("shaders/2/vertex.glsl", GL_VERTEX_SHADER), fragment("shaders/2/fragment.glsl", GL_FRAGMENT_SHADER);
        ShaderProgram shaderProgram({vertex, fragment});
        shaderProgram.useProgram();
    }
   catch(const GLSLShaderProgramLinkFailedException& e){
        std::cout<<e.what()<<std::endl;
   }


    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0); 
    



    context.runEventLoop();

    context.terminateContext();
    return 0;
}