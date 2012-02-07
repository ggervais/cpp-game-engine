#include "GLShader.hpp"

GLShader::GLShader(ShaderType type, std::string filename) :
    Shader(type, filename)
{}

GLShader::~GLShader() {
    std::cout << "Deleting shader " << this->id << "." << std::endl;
    glDeleteShader(this->id);
}

char *GLShader::getErrorLog() const {
    int infoLogLength = 0;
    glGetShaderiv(this->id, GL_INFO_LOG_LENGTH, &infoLogLength);
        
    char *log = (char *) malloc(infoLogLength * sizeof(char));
    glGetShaderInfoLog(this->id, infoLogLength, NULL, log);    

    return log;
}

GLenum GLShader::getShaderType() const {
    GLenum glShaderType;
    if (this->type == VERTEX_SHADER) {
        glShaderType = GL_VERTEX_SHADER;
    } else if (this->type == GEOMETRY_SHADER) {
        glShaderType = GL_GEOMETRY_SHADER;
    } else {
        glShaderType = GL_FRAGMENT_SHADER;
    }
    return glShaderType;
}

bool GLShader::compile() {

    bool success = true;

    std::string shaderSource = loadSource();

    if (shaderSource.length() == 0) {
        return false;
    }
    
    GLenum glShaderType = getShaderType();

    const char *source = shaderSource.c_str();
    const GLint length = shaderSource.length();

    this->id = glCreateShader(glShaderType);
    
    glShaderSource(this->id, 1, &source, &length); 

    glCompileShader(this->id);
    
    int compileSuccess = 0;
    glGetShaderiv(this->id, GL_COMPILE_STATUS, &compileSuccess);

    if (compileSuccess == 0) {
        
        success = false;

        char *errorLog = getErrorLog();
        
        std::cerr << "Shader compilation failed: " << std::endl;
        std::cerr << errorLog << std::endl;
        
        free(errorLog);

    }


    return success;
}

void* GLShader::getValue() const {
    return (void *) &this->id;
}

void GLShader::setValue(void *value) {
    this->id = *((GLuint *) value);
}