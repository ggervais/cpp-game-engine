#ifndef PROGRAM_HPP
#define	PROGRAM_HPP

#include <fstream>
#include <string>
#include <iostream>
#include <assert.h>
#include "Shader.hpp"
#include "RendererObject.hpp"
#include "../math/Matrix4x4.hpp"
#include "../math/Vector3D.hpp"
#include "VertexBuffer.hpp"

class Program : public RendererObject {
public:
    Program(Shader *vertexShader, Shader *fragmentShader);
    virtual ~Program();
    virtual bool link() = 0;
    virtual void registerUniform(std::string name) = 0;
    virtual void registerAttribute(std::string name) = 0;
    
    virtual void setIntegerUniform(std::string name, int &value) = 0;
    virtual void setFloatUniform(std::string name, float &value) = 0;
    virtual void setDoubleUniform(std::string name, double &value) = 0;
    virtual void setVector3DUniform(std::string name, Vector3D &value) = 0;
    virtual void setMatrix4x4Uniform(std::string name, Matrix4x4 &value) = 0;
    
    virtual void enableAttribute(std::string name) = 0;
    virtual void disableAttribute(std::string name) = 0;

    virtual void enableAttributes(VertexBuffer &vertexBuffer, int vertexAttributes) = 0;
    virtual void disableAttributes(VertexBuffer &vertexBuffer, int vertexAttributes) = 0;

    virtual void activate() = 0;
    virtual void deactivate() = 0;

    void* getValue() const = 0;
    void setValue(void *value) = 0;



protected:
    Shader *vertexShader;
    Shader *fragmentShader;
};

#endif	/* PROGRAM_HPP */

