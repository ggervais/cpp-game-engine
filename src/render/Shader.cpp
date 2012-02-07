#include "Shader.hpp"

Shader::Shader(ShaderType type, std::string filename) :
    type(type), filename(filename)
{}

Shader::~Shader() {}

std::string Shader::loadSource() {
    std::ifstream file(this->filename);
    std::string line;
    std::string shaderSource;

    while(std::getline(file, line)) {
        shaderSource.append(line).append("\n");
    }

    return shaderSource;
}