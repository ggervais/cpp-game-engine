/* 
 * File:   RenderingContext.hpp
 * Author: Guillaume
 *
 * Created on January 29, 2012, 6:52 PM
 */

#ifndef RENDEREROBJECT_HPP
#define	RENDEREROBJECT_HPP

#include <iostream>

template<typename T>
class RendererObject {
public:
    RendererObject();
    RendererObject(const RendererObject& orig);
    virtual ~RendererObject();
    virtual T getValue() const;
    virtual void setValue(T value);
private:
    T value;
};

#endif	/* RENDEREROBJECT_HPP */

