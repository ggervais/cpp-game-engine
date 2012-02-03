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

void Renderer::render(VertexBuffer &vertexBuffer) {
    updateViewport();
    doRender(vertexBuffer);
    canvas->centerCursor();
    canvas->repaint();
    
}

bool Renderer::isWindowOpened() {
    return canvas->isWindowOpened();
}
