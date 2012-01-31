/* 
 * File:   Renderer.cpp
 * Author: Guillaume
 * 
 * Created on January 17, 2012, 9:31 PM
 */

#include "Renderer.hpp"

Renderer::Renderer(Canvas *canvas) :
        canvas(canvas)
{}

Renderer::Renderer(const Renderer& orig) :
        canvas(orig.canvas)
{
    // TODO: clone instead.
}

Renderer::~Renderer() {}

bool Renderer::init() {}

void Renderer::render() {
    std::cout << "Before render() (Renderer.hpp)." << std::endl;
    updateViewport();
    doRender();
    canvas->centerCursor();
    canvas->repaint();
    std::cout << "After render() (Renderer.hpp)." << std::endl;
    
}

bool Renderer::isWindowOpened() {
    return canvas->isWindowOpened();
}
