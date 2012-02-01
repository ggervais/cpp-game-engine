/* 
 * File:   Renderer.hpp
 * Author: Guillaume
 *
 * Created on January 17, 2012, 9:31 PM
 */

#ifndef RENDERER_HPP
#define	RENDERER_HPP

#include <iostream>
#include "../ui/Canvas.hpp"
#include "../math/Matrix4x4.hpp"
#include "VertexBuffer.hpp"

const float PI = 3.14159265;

class Renderer {
public:
    Renderer(Canvas *canvas);
    Renderer(const Renderer& orig);
    virtual ~Renderer();
    virtual bool init();
    bool isWindowOpened();
    void render();
    
    virtual void createVertexBuffer(VertexBuffer &buffer) = 0;
    virtual void updateVertexBufferData(VertexBuffer &buffer) = 0;
    virtual void deleteVertexBuffer(VertexBuffer &buffer) = 0;
    
protected:
    virtual void updateViewport() = 0;
    virtual void doRender() = 0;
    Canvas *canvas;
    
};

#endif	/* RENDERER_HPP */

