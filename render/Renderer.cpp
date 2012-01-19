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

void Renderer::render() {
    doRender();
    canvas->centerCursor();
    canvas->repaint();
}
