#include "GLProgram.hpp"

GLProgram::GLProgram(Shader *vertexShader, Shader *fragmentShader) :
    Program(vertexShader, fragmentShader)
{}

GLProgram::~GLProgram() {
    std::cout << "Deleting program " << this->id << "." << std::endl;
    glDeleteProgram(this->id);
}

char *GLProgram::getErrorLog() const {
    int infoLogLength = 0;
    glGetProgramiv(this->id, GL_INFO_LOG_LENGTH, &infoLogLength);
        
    char *log = (char *) malloc(infoLogLength * sizeof(char));
    glGetProgramInfoLog(this->id, infoLogLength, NULL, log);    

    return log;
}


bool GLProgram::link() {
    bool success = true;

    this->id = glCreateProgram();
    if (id > 0) {
        GLuint vertexShaderId = *((GLuint *) this->vertexShader->getValue());
        GLuint fragmentShaderId = *((GLuint *) this->fragmentShader->getValue());
        
        std::cout << "Linking vertex shader id " << vertexShaderId 
                  << " and fragment shader id " << fragmentShaderId 
                  << " into program id " << this->id
                  << "." << std::endl;

        glAttachShader(this->id, vertexShaderId);
        glAttachShader(this->id, fragmentShaderId);
        glLinkProgram(this->id);

        int linkSuccess = 0;
        glGetProgramiv(this->id, GL_LINK_STATUS, &linkSuccess);

        if (linkSuccess == 0) {
        
            success = false;

            char *errorLog = getErrorLog();
        
            std::cerr << "Program link failed: " << std::endl;
            std::cerr << errorLog << std::endl;
        
            free(errorLog);

        }
    }

    return success;
}

void GLProgram::registerUniform(std::string name) {
    GLuint location = glGetUniformLocation(this->id, name.c_str());
    this->uniforms[name] = location;
    std::cout << "Generated location " << location << " for uniform " << name << ", OpenGL error is " << glGetError() << "." << std::endl;
}

void GLProgram::registerAttribute(std::string name) {
    GLuint location = glGetAttribLocation(this->id, name.c_str());
    this->attributes[name] = location;
    std::cout << "Generated location " << location << " for attribute " << name << ", OpenGL error is " << glGetError() << "." << std::endl;
}

void* GLProgram::getValue() const {
    return (void *) this->id;
}

void GLProgram::setValue(void *value) {
    this->id = *((GLuint *) value);
}