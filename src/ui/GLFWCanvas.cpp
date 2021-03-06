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
    glfwSetMousePos(width / 2, height / 2);        
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

void GLFWCALL GLFWCanvas::resizeCanvas(GLsizei width, GLsizei height) {
    glfwViewport->updateDimensions(width, height);
}

void GLFWCanvas::centerCursor() {
    Viewport &viewport = getViewport();
    glfwDisable(GLFW_MOUSE_CURSOR);
    glfwSetMousePos(viewport.getWidth() / 2, viewport.getHeight() / 2);
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
    
    //glfwDisable(GLFW_MOUSE_CURSOR);

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

bool GLFWCanvas::isWindowOpened() const {
    return glfwGetWindowParam(GLFW_OPENED) == 1;
}
