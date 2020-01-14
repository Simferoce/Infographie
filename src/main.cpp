#include <iostream>
#define GLEW_STATIC
#include "GL/glew.h"
#include "GLFW/glfw3.h"

int main() {
    //INITIALIZING GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    std::cout <<"Opening window..." << std::endl;
    GLFWwindow* window;
    if (glfwInit())
    {
        std::cout <<"Initialized GLFW" << std::endl;
         window= glfwCreateWindow(900,500, "title", NULL, NULL);
        if (!window)
        {
            return 1;
        }
        glfwMakeContextCurrent(window);
    }
    //INITIALIZING GLEW
    glewInit() == GLEW_OK ?
    std::cout << "Initialized GLEW" << std::endl :
    std::cerr << "FAILED:GLEW INITIALIZATION" << std::endl;

    glClearColor(1,0,0,0);
    //MAIN LOOP
    while(!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        if(glfwGetKey(window,GLFW_KEY_ESCAPE))
        {
            glfwSetWindowShouldClose(window,true);
        }
        glfwSwapBuffers(window);
        glfwPollEvents();

    }
    //CLEANUP
    glfwTerminate();
    return 0;
}