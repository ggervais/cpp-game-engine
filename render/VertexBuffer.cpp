/* 
 * File:   VertexBuffer.cpp
 * Author: Guillaume
 * 
 * Created on January 31, 2012, 10:08 PM
 */

#include "VertexBuffer.hpp"

VertexBuffer::VertexBuffer() : handle(NULL) {
    std::cout << "Creating VertexBuffer" << std::endl;
}

VertexBuffer::VertexBuffer(const VertexBuffer& orig) :
    handle(orig.handle) 
{
}

VertexBuffer::~VertexBuffer() {
}

RendererObject *VertexBuffer::getHandle() const {
    return this->handle;
}

void VertexBuffer::setHandle(RendererObject *handle) {
    this->handle = handle;
}
