/* 
 * File:   GLFWInput.hpp
 * Author: Guillaume
 *
 * Created on January 22, 2012, 1:51 AM
 */

#ifndef GLFWINPUT_HPP
#define	GLFWINPUT_HPP

#include "Input.hpp"
#include <map>

typedef int GLFWKey;

class GLFWInput : public Input {
public:
    GLFWInput();
    virtual ~GLFWInput();
    bool isKeyPressed(Key key) const;
private:
    std::map<Key, GLFWKey> glfwKeyMapping;
};

#endif	/* GLFWINPUT_HPP */

