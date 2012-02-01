/* 
 * File:   GLRendererObject.hpp
 * Author: Guillaume
 *
 * Created on January 31, 2012, 11:55 PM
 */

#ifndef GLRENDEREROBJECT_HPP
#define	GLRENDEREROBJECT_HPP

#include <GL/glew.h>
#include "RendererObject.hpp"

class GLRendererObject : public RendererObject {
public:
    GLRendererObject();
    GLRendererObject(const GLRendererObject& orig);
    virtual ~GLRendererObject();
    void setValue(void *value);
    void* getValue() const;
private:
    GLuint value;
};

#endif	/* GLRENDEREROBJECT_HPP */

