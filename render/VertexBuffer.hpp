/* 
 * File:   VertexBuffer.hpp
 * Author: Guillaume
 *
 * Created on January 31, 2012, 10:08 PM
 */

#ifndef VERTEXBUFFER_HPP
#define	VERTEXBUFFER_HPP

#include "RendererObject.hpp"

class VertexBuffer {
public:
    VertexBuffer();
    VertexBuffer(const VertexBuffer& orig);
    virtual ~VertexBuffer();
    RendererObject *getHandle() const;
    void setHandle(RendererObject *handle);
private:
    RendererObject *handle;
};

#endif	/* VERTEXBUFFER_HPP */

