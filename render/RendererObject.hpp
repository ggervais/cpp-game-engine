/* 
 * File:   RenderingContext.hpp
 * Author: Guillaume
 *
 * Created on January 29, 2012, 6:52 PM
 */

#ifndef RENDEREROBJECT_HPP
#define	RENDEREROBJECT_HPP

#include <iostream>
#include <vector>

class RendererObject {
public:
    virtual void* getValue() const = 0;
    virtual void setValue(void *value) = 0;
};

#endif	/* RENDEREROBJECT_HPP */

