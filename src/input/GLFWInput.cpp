/* 
 * File:   GLFWInput.cpp
 * Author: Guillaume
 * 
 * Created on January 22, 2012, 1:51 AM
 */

#include <GL/glfw.h>

#include "GLFWInput.hpp"

GLFWInput::GLFWInput() : 
    Input() {

    this->glfwKeyMapping[W] = 'W';
    this->glfwKeyMapping[A] = 'A';
    this->glfwKeyMapping[S] = 'S';
    this->glfwKeyMapping[D] = 'D';
    this->glfwKeyMapping[ESCAPE] = GLFW_KEY_ESC;
    this->glfwKeyMapping[SPACEBAR] = GLFW_KEY_SPACE;
}

GLFWInput::~GLFWInput() {
}


bool GLFWInput::isKeyPressed(Key key) const {

    bool isPressed = false;

    std::map<Key, GLFWKey>::const_iterator found = this->glfwKeyMapping.find(key);
    if (found != this->glfwKeyMapping.end()) {
        GLFWKey glfwKey = found->second;
        isPressed = (glfwGetKey(glfwKey) == GLFW_PRESS);
    }

    return isPressed;
}

Vector3D GLFWInput::getMousePosition() const {
    int x = 0;
    int y = 0;

    glfwGetMousePos(&x, &y);

    return Vector3D(x, y, 0);
}

Vector3D GLFWInput::getRelativeMousePosition() const {
    int x = 0;
    int y = 0;

    glfwGetMousePos(&x, &y);

    return Vector3D(x, y, 0);
}