/* 
 * File:   GLVertexBuffer.cpp
 * Author: Guillaume
 * 
 * Created on January 31, 2012, 10:17 PM
 */

#include "GLVertexBuffer.hpp"

GLVertexBuffer::GLVertexBuffer() {
}

GLVertexBuffer::GLVertexBuffer(const GLVertexBuffer& orig) {
}

GLVertexBuffer::~GLVertexBuffer() {
}

void GLVertexBuffer::setValue(void* vboId) {
    this->vboId = *((GLuint*) vboId);
}

void* GLVertexBuffer::getValue() const {
    return (void*) &this->vboId;
}
