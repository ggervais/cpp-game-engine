#ifndef SHADER_HPP
#define	SHADER_HPP

#include <fstream>
#include <string>
#include <iostream>
#include "RendererObject.hpp"

enum ShaderType {
    VERTEX_SHADER,
    GEOMETRY_SHADER,
    FRAGMENT_SHADER
};

class Shader : public RendererObject {
public:
    Shader(ShaderType type, std::string filename);
    virtual ~Shader();
    virtual bool compile() = 0;
    virtual void* getValue() const = 0;
    virtual void setValue(void *value) = 0;
protected:
    ShaderType type;
    std::string filename;
    std::string loadSource();
};

#endif	/* SHADER_HPP */

