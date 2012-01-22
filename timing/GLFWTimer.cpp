/* 
 * File:   GLFWTimer.cpp
 * Author: Guillaume
 * 
 * Created on January 22, 2012, 1:06 AM
 */

#include "GLFWTimer.hpp"

GLFWTimer::GLFWTimer(double quantum) : 
        Timer(quantum)
{
}

GLFWTimer::~GLFWTimer() {
}

double GLFWTimer::getTime() const {
    return glfwGetTime();
}

void GLFWTimer::sleep(double time) {
    glfwSleep(time);
}
