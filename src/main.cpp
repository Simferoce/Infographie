#include <iostream>

#define GLEW_STATIC

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "VAO.h"
#include "Geometry.h"
#include "ShaderProgram.h"
#include "vector"

int main() {
    //INITIALIZING GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow *window;
    if (glfwInit()) {
        std::cout << "Initialized GLFW" << std::endl;
        window = glfwCreateWindow(900, 600, "title", NULL, NULL);
        if (!window) {
            return 1;
        }
        glfwMakeContextCurrent(window);
    }
    //INITIALIZING GLEW
    glewInit() == GLEW_OK ?
    std::cout << "Initialized GLEW" << std::endl :
    std::cerr << "FAILED:GLEW INITIALIZATION" << std::endl;

    //SETTING CLEAR COLOR BLACK
    glClearColor(0, 0, 0, 0);

    //INITIALIZING BEFORE LOOP
    //creating the shader
    const std::string sourceFrag = "../src/ShaderSource/vertex.glsl";
    const std::string sourceVert = "../src/ShaderSource/fragment.glsl";
    ShaderProgram shaderProgram = ShaderProgram(sourceFrag, sourceVert);

    //creating the mesh
    VAO mesh = VAO();
    //utility namespace to create geometry
    Geometry::makeQuad(mesh);
    //setting colors of vertices
    float *colors = new float[16]{1, 1, 1, 1,//white
                                  1, 0, 0, 0,//red
                                  0, 1, 0, 0,//green
                                  0, 0, 1, 0//blue
    };
    //put at the layout position 3 an attribute with 4 values per vertex, that has the values colors that have 16 elements
    //look at the shader code in vertex to see what is the layout position of the atribute
    //layout(location=3)in vec4 colors;
    //layout position=3 and it is a vec4 so its 4 value per vertex
    mesh.put(3,4,colors, 16);

    //MAIN LOOP
    while (!glfwWindowShouldClose(window)) {
        //Get inputs
        glfwPollEvents();
        //Update
        if (glfwGetKey(window, GLFW_KEY_ESCAPE)) {
            glfwSetWindowShouldClose(window, true);
        }
        //Render
        glClear(GL_COLOR_BUFFER_BIT);
        shaderProgram.bind();
        mesh.bind();
        glDrawElements(GL_TRIANGLES, mesh.getVertexCount(), GL_UNSIGNED_INT, nullptr);
        mesh.unbind();
        shaderProgram.unbind();
        glfwSwapBuffers(window);

    }
    //CLEANUP
    glfwTerminate();
    return 0;
}