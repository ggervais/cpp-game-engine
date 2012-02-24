#include "Program.hpp"

Program::Program(Shader *vertexShader, Shader *geometryShader, Shader *fragmentShader) : 
    vertexShader(vertexShader), geometryShader(geometryShader), fragmentShader(fragmentShader)   
{
    assert(vertexShader && geometryShader && fragmentShader);
}

Program::Program(Shader *vertexShader, Shader *fragmentShader) :
    vertexShader(vertexShader), fragmentShader(fragmentShader)
{
    assert(vertexShader && fragmentShader);
}

Program::~Program() {}