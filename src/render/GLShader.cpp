#include "GLShader.hpp"

GLShader::GLShader(ShaderType type, std::string filename) :
    Shader(type, filename)
{}

GLShader::~GLShader() {
}

bool GLShader::compile() {

    bool success = true;

    std::ifstream file(this->filename);
    std::string line;
    std::string shaderSource;

    while(std::getline(file, line)) {
        shaderSource.append(line).append("\n");
    }

    std::cout << shaderSource << std::endl;
    
    GLenum glShaderType;
    if (this->type == VERTEX_SHADER) {
        glShaderType = GL_VERTEX_SHADER;
    } else if (this->type == GEOMETRY_SHADER) {
        glShaderType = GL_GEOMETRY_SHADER;
    } else {
        glShaderType = GL_FRAGMENT_SHADER;
    }

    const char *source = shaderSource.c_str();
    const GLint length = shaderSource.length();

    this->id = glCreateShader(glShaderType);
    glShaderSource(this->id, 1, &source, &length); 

    glCompileShader(this->id);
    
    int compileSuccess = 0;
    glGetShaderiv(this->id, GL_COMPILE_STATUS, &compileSuccess);

    if (compileSuccess == 0) {
        
        success = false;

        int infoLogLength = 0;
        glGetShaderiv(this->id, GL_INFO_LOG_LENGTH, &infoLogLength);
        
        char *log = (char *) malloc(infoLogLength * sizeof(char));
        glGetShaderInfoLog(this->id, infoLogLength, NULL, log);
        
        std::cout << log << std::endl;
        
        free(log);

    }


    return success;
}