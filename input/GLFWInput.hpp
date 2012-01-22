/* 
 * File:   GLFWInput.hpp
 * Author: Guillaume
 *
 * Created on January 22, 2012, 1:51 AM
 */

#ifndef GLFWINPUT_HPP
#define	GLFWINPUT_HPP

#include "Input.hpp"
#include <GL/glfw.h>

class GLFWInput : public Input {
public:
    GLFWInput();
    virtual ~GLFWInput();
    bool isEscapePressed() const;
private:

};

#endif	/* GLFWINPUT_HPP */

