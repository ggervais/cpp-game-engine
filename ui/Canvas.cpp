/* 
 * File:   Canvas.cpp
 * Author: Guillaume
 * 
 * Created on January 17, 2012, 9:32 PM
 */

#include "Canvas.hpp"

Canvas::Canvas(std::string title, int width, int height, bool fullscreen) : 
        title(title),
        viewport(width, height, fullscreen)
{
    std::cout << "Constructing canvas" << std::endl;
}

Canvas::Canvas(const Canvas& orig) : 
        title(orig.title), 
        viewport(orig.viewport)
{}

Canvas::~Canvas() {
    std::cout << "Destroying canvas" << std::endl;
}

Viewport &Canvas::getViewport() {
    return this->viewport;
}

bool Canvas::init() {}
