#ifndef SHADER_HPP
#define	SHADER_HPP

#include <iostream>

enum ShaderType {
    VERTEX_SHADER,
    GEOMETRY_SHADER,
    FRAGMENT_SHADER
};

class Shader {
public:
    Shader(ShaderType type, std::string filename);
    virtual bool compile() = 0;
protected:
    ShaderType type;
    std::string filename;
};

#endif	/* SHADER_HPP */

