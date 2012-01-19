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

void GLFWCanvas::resizeCanvas(GLsizei width, GLsizei height) {
    std::cout << "Resize" << std::endl;
    glfwViewport->updateDimensions(width, height);
}

bool GLFWCanvas::init() {
    
    
    Viewport &viewport = getViewport();
    
    std::cout << "Creating canvas with title \"" << title << "\" and size " << viewport.getWidth() << "x" << viewport.getHeight() << "." << std::endl;
    
    // Hack for GLFW.
    glfwViewport = &viewport;
    
    int redBits = 8;
    int greenBits = 8;
    int blueBits = 8;
    int alphaBits = 8;
    int depthBits = 32;
    int stencilBits = 8;
    
    glfwInit();
    
    glfwOpenWindowHint(GLFW_FSAA_SAMPLES, 4);
    
    // Create a window
    if(!glfwOpenWindow(viewport.getWidth(), viewport.getHeight(), redBits, greenBits, blueBits, alphaBits, depthBits, stencilBits, (viewport.isFullscreen() ? GLFW_FULLSCREEN : GLFW_WINDOW))) {
        std::cerr << "Failed to open window!" << std::endl;
        glfwTerminate();
        return false;
    }
    
    glfwSetWindowTitle("Guillaume Gervais' C++ Game Engine");
    glfwSwapInterval(1);
    
    glfwSetWindowSizeCallback(GLFWCanvas::resizeCanvas);
    
    return true;
}

