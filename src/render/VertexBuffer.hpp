/* 
 * File:   VertexBuffer.hpp
 * Author: Guillaume
 *
 * Created on January 31, 2012, 10:08 PM
 */

#ifndef VERTEXBUFFER_HPP
#define	VERTEXBUFFER_HPP

#include "RendererObject.hpp"
#include "vertex.hpp"

class VertexBuffer {
public:
    VertexBuffer();
    VertexBuffer(const VertexBuffer& orig);
    virtual ~VertexBuffer();
    
    RendererObject *getVBOHandle() const;
    void setVBOHandle(RendererObject *handle);
    
    RendererObject *getIBOHandle() const;
    void setIBOHandle(RendererObject *handle);
    
    void addVertex(Vertex v);
    void addIndex(unsigned int i);
    
    int getVBOSize();
    int getIBOSize();
    
    bool isVBODirty();
    void setVBODirty(bool dirty);
    
    bool isIBODirty();
    void setIBODirty(bool dirty);
    
    Vertex *getVBOData();
    unsigned int *getIBOData();
    
private:
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    RendererObject *vboHandle;
    RendererObject *iboHandle;
    bool vboDirty;
    bool iboDirty;
};

#endif	/* VERTEXBUFFER_HPP */

