/* 
 * File:   GLFWInput.cpp
 * Author: Guillaume
 * 
 * Created on January 22, 2012, 1:51 AM
 */

#include <GL/glfw.h>

#include "GLFWInput.hpp"

GLFWInput::GLFWInput() {
}

GLFWInput::~GLFWInput() {
}

bool GLFWInput::isEscapePressed() const {
	std::cout << "Is Escape Pressed: " << glfwGetKey(GLFW_KEY_ESC) << std::endl;
    return glfwGetKey(GLFW_KEY_ESC) == 1;
}

