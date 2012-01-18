/* 
 * File:   Canvas.hpp
 * Author: Guillaume
 *
 * Created on January 17, 2012, 9:32 PM
 */

#ifndef CANVAS_HPP
#define	CANVAS_HPP

#include <iostream>

class Canvas {

public:
    virtual void sayType() = 0;
    
protected:
    Canvas(std::string title, int width, int height, bool fullscreen);
    Canvas(const Canvas& orig);
    virtual ~Canvas();
    
    std::string title;
    int width;
    int height;
    bool fullscreen;
};

#endif	/* CANVAS_HPP */

