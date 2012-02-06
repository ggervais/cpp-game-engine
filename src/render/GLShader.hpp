#ifndef GLSHADER_HPP
#define	GLSHADER_HPP

#include <iostream>
#include "Shader.hpp"
#include <GL/glew.h>
#include <fstream>
#include <string>

class GLShader : public Shader {
public:
    GLShader(ShaderType type, std::string filename);
    ~GLShader();
    bool compile();
private:
    GLuint id;
};

#endif	/* GLSHADER_HPP */

