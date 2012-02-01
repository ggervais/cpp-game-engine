/* 
 * File:   GLRendererObject.cpp
 * Author: Guillaume
 * 
 * Created on January 31, 2012, 11:55 PM
 */

#include "GLRendererObject.hpp"
#include "RendererObject.hpp"

GLRendererObject::GLRendererObject() {
}

GLRendererObject::GLRendererObject(const GLRendererObject& orig) {
}

GLRendererObject::~GLRendererObject() {
}

void GLRendererObject::setValue(void* value) {
    this->value = *((GLuint*) value);
}
void* GLRendererObject::getValue() const {
    return (void*) &this->value;
}
