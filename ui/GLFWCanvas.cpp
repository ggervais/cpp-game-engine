/* 
 * File:   Window.cpp
 * Author: Guillaume
 * 
 * Created on January 17, 2012, 7:05 PM
 */

#include "GLFWCanvas.hpp"

GLFWCanvas::GLFWCanvas(std::string title, int width, int height, bool fullscreen) : 
        Canvas(title, width, height, fullscreen) 
{
    init();
}

GLFWCanvas::GLFWCanvas(const GLFWCanvas& orig) :
        Canvas(orig)
{
}

GLFWCanvas::~GLFWCanvas() {
    std::cout << "Deleting canvas." << std::endl;
    glfwTerminate();
}

void GLFWCanvas::repaint() {
    glfwSwapBuffers();
}

void GLFWCanvas::sayType() {
    std::cout << "Type is GLFWCanvas" << std::endl;
}

bool GLFWCanvas::init() {
    
    std::cout << "Creating canvas with title \"" << title << "\" and size " << width << "x" << height << "." << std::endl;
    
    int redBits = 8;
    int greenBits = 8;
    int blueBits = 8;
    int alphaBits = 8;
    int depthBits = 32;
    int stencilBits = 8;
    
    glfwInit();
    
    glfwOpenWindowHint(GLFW_FSAA_SAMPLES, 4);
    
    // Create a window
    if(!glfwOpenWindow(width, height, redBits, greenBits, blueBits, alphaBits, depthBits, stencilBits, GLFW_WINDOW))
    {
        std::cerr << "Failed to open window!" << std::endl;
        glfwTerminate();
    }
}

