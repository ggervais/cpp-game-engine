#ifndef PROGRAM_HPP
#define	PROGRAM_HPP

#include <fstream>
#include <string>
#include <iostream>
#include <assert.h>
#include "Shader.hpp"
#include "RendererObject.hpp"

class Program : public RendererObject {
public:
    Program(Shader *vertexShader, Shader *fragmentShader);
    virtual ~Program();
    virtual bool link() = 0;
    virtual void registerUniform(std::string name) = 0;
    virtual void registerAttribute(std::string name) = 0;
    void* getValue() const = 0;
    void setValue(void *value) = 0;
protected:
    Shader *vertexShader;
    Shader *fragmentShader;
};

#endif	/* PROGRAM_HPP */

