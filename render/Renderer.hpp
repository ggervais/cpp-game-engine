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

class Renderer {
public:
    Renderer(Canvas *canvas);
    Renderer(const Renderer& orig);
    virtual ~Renderer();
    
    Canvas *canvas;
    
};

#endif	/* RENDERER_HPP */

