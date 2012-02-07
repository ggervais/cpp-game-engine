#ifndef GLSHADER_HPP
#define	GLSHADER_HPP

#include <iostream>
#include "Shader.hpp"
#include <GL/glew.h>


class GLShader : public Shader {
public:
    GLShader(ShaderType type, std::string filename);
    ~GLShader();
    bool compile();
    void* getValue() const;
    void setValue(void *value);
private:
    GLuint id;
    char *getErrorLog() const;
    GLenum getShaderType() const;
};

#endif	/* GLSHADER_HPP */

