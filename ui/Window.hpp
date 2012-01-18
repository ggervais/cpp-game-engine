/* 
 * File:   Window.hpp
 * Author: Guillaume
 *
 * Created on January 17, 2012, 7:05 PM
 */

#ifndef WINDOW_HPP
#define	WINDOW_HPP

#include <iostream>
#include <GL/glfw.h>

class Window {
public:
    Window(std::string title, int width, int height);
    Window(const Window& orig);
    virtual ~Window();
    
    void repaint();
private:
    std::string title;
    int width;
    int height;
    
    bool init();
};

#endif	/* WINDOW_HPP */

