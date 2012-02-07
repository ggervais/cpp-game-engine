#ifndef GLPROGRAM_HPP
#define	GLPROGRAM_HPP

#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <GL/glew.h>
#include "Program.hpp"

class GLProgram : public Program {
public:
    GLProgram(Shader *vertexShader, Shader *fragmentShader);
    ~GLProgram();
    bool link();
    void registerUniform(std::string name);
    void registerAttribute(std::string name);
    void* getValue() const;
    void setValue(void *value);
private:
    GLuint id;
    std::map<std::string, GLuint> uniforms;
    std::map<std::string, GLuint> attributes;
    char *getErrorLog() const;
};

#endif	/* GLPROGRAM_HPP */

