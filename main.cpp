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
#include "render/GLRenderer.hpp"

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

/*
 * 
 */
int main(int argc, char* argv[]) {

    // Flag to keep our main loop running
    bool running = true;

    GLFWCanvas canvas("Guillaume Gervais' C++ Game Engine", 640, 480, false);
    GLRenderer renderer(&canvas);
    
    while (running) {
        renderer.render();
        running = !glfwGetKey(GLFW_KEY_ESC) && glfwGetWindowParam(GLFW_OPENED);
    }
    
    return EXIT_SUCCESS;
}

