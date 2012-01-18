/* 
 * File:   Window.cpp
 * Author: Guillaume
 * 
 * Created on January 17, 2012, 7:05 PM
 */

#include "Window.hpp"

Window::Window(std::string title, int width, int height) : title(title), width(width), height(height) {
    init();
}

Window::Window(const Window& orig) {
}

Window::~Window() {
    std::cout << "Deleting window." << std::endl;
    glfwTerminate();
}

void Window::repaint() {
    glfwSwapBuffers();
}

bool Window::init() {
    
    std::cout << "Creating window with title \"" << title << "\" and size " << width << "x" << height << "." << std::endl;
    
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
    
    glfwSetWindowTitle("Guillaume Gervais' C++ Game Engine");
    glfwSwapInterval(1);
}

