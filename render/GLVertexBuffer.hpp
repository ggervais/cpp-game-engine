/* 
 * File:   GLVertexBuffer.hpp
 * Author: Guillaume
 *
 * Created on January 31, 2012, 10:17 PM
 */

#ifndef GLVERTEXBUFFER_HPP
#define	GLVERTEXBUFFER_HPP

#include "VertexBuffer.hpp"
#include <GL/glew.h>

class GLVertexBuffer : public VertexBuffer {
public:
    GLVertexBuffer();
    GLVertexBuffer(const GLVertexBuffer& orig);
    virtual ~GLVertexBuffer();
    
    void setValue(void* vboId);
    void* getValue() const;
    
private:
    GLuint vboId;
};

#endif	/* GLVERTEXBUFFER_HPP */

