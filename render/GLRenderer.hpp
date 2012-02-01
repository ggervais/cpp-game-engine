/* 
 * File:   GLRenderer.hpp
 * Author: Guillaume
 *
 * Created on January 18, 2012, 11:18 PM
 */

#ifndef GLRENDERER_HPP
#define	GLRENDERER_HPP

#include <GL/glew.h>
#include "Renderer.hpp"

class GLRenderer : public Renderer {
public:
    GLRenderer(Canvas *canvas);
    GLRenderer(const GLRenderer& orig);
    bool init();
    virtual ~GLRenderer();
    void createVertexBuffer(VertexBuffer &buffer);
    void updateVertexBufferData(VertexBuffer &buffer);
    void deleteVertexBuffer(VertexBuffer &buffer);
private:
    void updateViewport();
    void doRender();
};

#endif	/* GLRENDERER_HPP */

