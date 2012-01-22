/* 
 * File:   GLFWInput.cpp
 * Author: Guillaume
 * 
 * Created on January 22, 2012, 1:51 AM
 */

#include "GLFWInput.hpp"

GLFWInput::GLFWInput() {
}

GLFWInput::~GLFWInput() {
}

bool GLFWInput::isEscapePressed() const {
    return glfwGetKey(GLFW_KEY_ESC);
}

