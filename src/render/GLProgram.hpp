#ifndef GLPROGRAM_HPP
#define	GLPROGRAM_HPP

#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <GL/glew.h>
#include "vertex.hpp"
#include "Program.hpp"

#define BUFFER_OFFSET(a) ((char*)NULL + (a))

class GLProgram : public Program {
public:
    GLProgram(Shader *vertexShader, Shader *fragmentShader);
    ~GLProgram();
    bool link();
    
    void registerUniform(std::string name);
    void registerAttribute(std::string name);
    void setIntegerUniform(std::string name, int &value);
    void setFloatUniform(std::string name, float &value);
    void setDoubleUniform(std::string name, double &value);
    void setVector3DUniform(std::string name, Vector3D &value);
    void setMatrix4x4Uniform(std::string name, Matrix4x4 &value);

    void enableAttribute(std::string name);
    void disableAttribute(std::string name);

    void enableAttributes(VertexBuffer &vertexBuffer);
    void disableAttributes(VertexBuffer &vertexBuffer);

    void activate();
    void deactivate();

    void* getValue() const;
    void setValue(void *value);
private:
    GLuint id;
    std::map<std::string, GLuint> uniforms;
    std::map<std::string, GLuint> attributes;
    char *getErrorLog() const;
};

#endif	/* GLPROGRAM_HPP */

