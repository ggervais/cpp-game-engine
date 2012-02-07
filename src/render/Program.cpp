#include "Program.hpp"

Program::Program(Shader *vertexShader, Shader *fragmentShader) :
    vertexShader(vertexShader), fragmentShader(fragmentShader)
{
    assert(vertexShader && fragmentShader);
}

Program::~Program() {}