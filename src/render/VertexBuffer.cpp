/* 
 * File:   VertexBuffer.cpp
 * Author: Guillaume
 * 
 * Created on January 31, 2012, 10:08 PM
 */

#include "VertexBuffer.hpp"

VertexBuffer::VertexBuffer() : vboHandle(NULL), iboHandle(NULL), vboDirty(true), iboDirty(true) {
    std::cout << "Creating VertexBuffer" << std::endl;
    std::cout << "Size " << sizeof(Vertex) << std::endl;
}

VertexBuffer::VertexBuffer(const VertexBuffer& orig) :
    vboHandle(orig.vboHandle),
    iboHandle(orig.iboHandle)
{
}

VertexBuffer::~VertexBuffer() {
}

RendererObject *VertexBuffer::getVBOHandle() const {
    return this->vboHandle;
}

void VertexBuffer::setVBOHandle(RendererObject *handle) {
    this->vboHandle = handle;
}

RendererObject *VertexBuffer::getIBOHandle() const {
    return this->iboHandle;
}

void VertexBuffer::setIBOHandle(RendererObject *handle) {
    this->iboHandle = handle;
}

void VertexBuffer::addVertex(Vertex v) {
    this->vertices.push_back(v);
}

void VertexBuffer::addIndex(unsigned int i) {
    this->indices.push_back(i);
}

int VertexBuffer::getVBOSize() {
    return this->vertices.size();
}

int VertexBuffer::getIBOSize() {
    return this->indices.size();
}

bool VertexBuffer::isVBODirty() {
    return this->vboDirty;
}

void VertexBuffer::setVBODirty(bool dirty) {
    this->vboDirty = dirty;
}

bool VertexBuffer::isIBODirty() {
    return this->iboDirty;
}

void VertexBuffer::setIBODirty(bool dirty) {
    this->iboDirty = dirty;
}

Vertex *VertexBuffer::getVBOData() {
    return &this->vertices[0];
}

unsigned int *VertexBuffer::getIBOData() {
    return &this->indices[0];
}

bool VertexBuffer::isInitialized() {
    return this->iboHandle != NULL && this->vboHandle != NULL;
}