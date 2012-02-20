/* 
 * File:   GLRenderer.hpp
 * Author: Guillaume
 *
 * Created on January 18, 2012, 11:18 PM
 */

#ifndef GLRENDERER_HPP
#define	GLRENDERER_HPP

#include <GL/glew.h>
#include "GLShader.hpp"
#include "GLProgram.hpp"
#include "Renderer.hpp"

#define BUFFER_OFFSET(a) ((char*)NULL + (a))

class GLRenderer : public Renderer {
public:
    GLRenderer(Canvas *canvas);
    GLRenderer(const GLRenderer& orig);
    bool init();
    
    void clearScreen();
    virtual ~GLRenderer();
    void createVertexBuffer(VertexBuffer &buffer);
    void updateVertexBufferData(VertexBuffer &buffer);
    void deleteVertexBuffer(VertexBuffer &buffer);

    Shader *createShader(ShaderType type, std::string filename);
    void deleteShader(Shader *shader);

    Program *createProgram(Shader *vertexShader, Shader *fragmentShader);
    void deleteProgram(Program *program);

    void renderIndexedVBO(VertexBuffer &vertexBuffer);
private:
    void updateViewport();
    void doRender(VertexBuffer &vertexBuffer);
};

#endif	/* GLRENDERER_HPP */

