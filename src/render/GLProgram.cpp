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


void GLProgram::setIntegerUniform(std::string name, int &value) {
    glUniform1i(this->uniforms[name], value);
}

void GLProgram::setFloatUniform(std::string name, float &value) {
    glUniform1f(this->uniforms[name], value);
}

void GLProgram::setDoubleUniform(std::string name, double &value) {
    glUniform1d(this->uniforms[name], value);
}

void GLProgram::setVector3DUniform(std::string name, Vector3D &value) {
    glUniform3fv(this->uniforms[name], 1, value.get());
}

void GLProgram::setMatrix4x4Uniform(std::string name, Matrix4x4 &value) {
    Matrix4x4 colMajor = Matrix4x4::createColumnMajor(value);
    glUniformMatrix4fv(this->uniforms[name], 1, false, colMajor.get());
}

void GLProgram::enableAttribute(std::string name) {
    glEnableVertexAttribArray(this->attributes[name]);
}

void GLProgram::disableAttribute(std::string name) {
    glDisableVertexAttribArray(this->attributes[name]);
}

void GLProgram::enableAttributes(VertexBuffer &vertexBuffer) {
    
    RendererObject *vbo = vertexBuffer.getVBOHandle();
    GLuint vboId = *((GLuint*) vbo->getValue());

    GLint currentlyBoundVBO = 0;
    glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &currentlyBoundVBO);

    if (currentlyBoundVBO != vboId) {
        glBindBuffer(GL_ARRAY_BUFFER, vboId);
    }

    glVertexAttribPointer(this->attributes["position"], 3, GL_FLOAT, false, sizeof(Vertex), BUFFER_OFFSET(0));
    glVertexAttribPointer(this->attributes["color"], 4, GL_FLOAT, false, sizeof(Vertex), BUFFER_OFFSET(sizeof(float) * 3));
    glEnableVertexAttribArray(this->attributes["position"]);
    glEnableVertexAttribArray(this->attributes["color"]);
    /*for (std::map<std::string, GLuint>::iterator it = this->attributes.begin(); it != this->attributes.end(); it++) {
        std::string key = (*it).first;
        enableAttribute(key);
    }*/
}

void GLProgram::disableAttributes(VertexBuffer &vertexBuffer) {
    
    glDisableVertexAttribArray(this->attributes["color"]);
    glDisableVertexAttribArray(this->attributes["position"]);
    /*for (std::map<std::string, GLuint>::iterator it = this->attributes.begin(); it != this->attributes.end(); it++) {
        std::string key = (*it).first;
        disableAttribute(key);
    }*/
}

void GLProgram::activate() {
    glUseProgram(this->id);
}

void GLProgram::deactivate() {
    glUseProgram(0);
}


void* GLProgram::getValue() const {
    return (void *) this->id;
}

void GLProgram::setValue(void *value) {
    this->id = *((GLuint *) value);
}