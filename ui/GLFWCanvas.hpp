/* 
 * File:   Window.hpp
 * Author: Guillaume
 *
 * Created on January 17, 2012, 7:05 PM
 */

#ifndef WINDOW_HPP
#define	WINDOW_HPP

#include <GL/glfw.h>
#include "Canvas.hpp"

class GLFWCanvas : public Canvas {
public:
    GLFWCanvas(std::string title, int width, int height, bool fullscreen);
    GLFWCanvas(const GLFWCanvas& orig);
    virtual ~GLFWCanvas();
    void sayType();
    void repaint();
private:
    
    bool init();
};

#endif	/* WINDOW_HPP */

