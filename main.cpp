/* 
 * File:   main.cpp
 * Author: Guillaume
 *
 * Created on January 16, 2012, 9:37 PM
 * 
 * The OpenGL initialization will be put into a GLRenderer class of some sort
 * later.
 * 
 * This is only a skeleton, using mostly C-style code.
 */

#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <GL/glew.h>
#include <GL/glfw.h>

#include "ui/GLFWCanvas.hpp"
#include "render/Renderer.hpp"

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

void render(GLFWCanvas &canvas) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1, 0, 1, 1);
    canvas.repaint();
}

/*
 * 
 */
int main(int argc, char* argv[]) {

    // Flag to keep our main loop running
    bool running = true;

    GLFWCanvas canvas("Guillaume Gervais' C++ Game Engine", 640, 480, false);
    
    Renderer renderer(&canvas);
    
    GLenum status = glewInit();
    if (GLEW_OK != status) {
        std::cerr << "Could not initialize GLEW, error: " << glewGetErrorString(status) << std::endl;
        return EXIT_FAILURE;
    }
    
    std::string glewVersion = (char *) glewGetString(GLEW_VERSION);
    std::string glVersion = (char *) glGetString(GL_VERSION);
    std::string glslVersion = (char *) glGetString(GL_SHADING_LANGUAGE_VERSION);
    std::string glExtensions = (char *) glGetString(GL_EXTENSIONS);
    
    std::cout << "GLEW version: " << glewVersion << std::endl;
    std::cout << "OpenGL version: " << glVersion << std::endl;
    std::cout << "GLSL version: " << glslVersion << std::endl;
    std::cout << "OpenGL extensions: " << glExtensions << std::endl;
    
    
    glfwSetWindowTitle("Guillaume Gervais' C++ Game Engine");
    glfwSwapInterval(1);
    
    while (running) {
        render(canvas);
        running = !glfwGetKey(GLFW_KEY_ESC) && glfwGetWindowParam(GLFW_OPENED);
    }
    
    return EXIT_SUCCESS;
}

