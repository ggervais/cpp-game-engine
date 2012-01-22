/* 
 * File:   Canvas.hpp
 * Author: Guillaume
 *
 * Created on January 17, 2012, 9:32 PM
 */

#ifndef CANVAS_HPP
#define	CANVAS_HPP

#include <iostream>
#include "../render/Viewport.hpp"

class Canvas {

public:
    Viewport &getViewport();
    virtual void centerCursor() = 0;
    virtual void repaint() = 0;
    virtual bool isWindowOpened() const = 0;
    virtual bool init();
    
protected:
    Canvas(std::string title, int width, int height, bool fullscreen);
    Canvas(const Canvas& orig);
    virtual ~Canvas();
    
    std::string title;
    
private:
    Viewport viewport;
};

#endif	/* CANVAS_HPP */

