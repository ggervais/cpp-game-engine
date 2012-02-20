/* 
 * File:   Renderer.hpp
 * Author: Guillaume
 *
 * Created on January 17, 2012, 9:31 PM
 */

#ifndef RENDERER_HPP
#define	RENDERER_HPP

#include <iostream>
#include "../ui/Canvas.hpp"
#include "../math/Matrix4x4.hpp"
#include "VertexBuffer.hpp"
#include "Shader.hpp"
#include "Program.hpp"

const float PI = 3.14159265f;

class Renderer {
public:
    Renderer(Canvas *canvas);
    Renderer(const Renderer& orig);
    virtual ~Renderer();
    virtual bool init() = 0;
    bool isWindowOpened();
    void render(VertexBuffer &vertexBuffer);
    
    virtual void clearScreen() = 0;

    virtual void createVertexBuffer(VertexBuffer &buffer) = 0;
    virtual void updateVertexBufferData(VertexBuffer &buffer) = 0;
    virtual void deleteVertexBuffer(VertexBuffer &buffer) = 0;

    virtual Shader *createShader(ShaderType type, std::string filename) = 0;
    virtual void deleteShader(Shader *shader) = 0;
 
    virtual Program *createProgram(Shader *vertexShader, Shader *fragmentShader) = 0;
    virtual void deleteProgram(Program *program) = 0;

    virtual void renderIndexedVBO(VertexBuffer &vertexBuffer) = 0;
    
protected:
    virtual void updateViewport() = 0;
    virtual void doRender(VertexBuffer &vertexBuffer) = 0;
    Canvas *canvas;
    
};

#endif	/* RENDERER_HPP */

