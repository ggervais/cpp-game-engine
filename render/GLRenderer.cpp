/* 
 * File:   GLRenderer.cpp
 * Author: Guillaume
 * 
 * Created on January 18, 2012, 11:18 PM
 */

#include "GLRenderer.hpp"
#include "RendererObject.hpp"

float rotation;

GLRenderer::GLRenderer(Canvas *canvas) :
        Renderer(canvas) {}

GLRenderer::GLRenderer(const GLRenderer& orig) :
        Renderer(orig)
{
}

GLRenderer::~GLRenderer() {
}

bool GLRenderer::init() {
   
    rotation = 0;
    
    this->canvas->init();
    
    std::cout << "GLRenderer init." << std::endl;
    
    GLenum status = glewInit();
    if (GLEW_OK != status) {
        std::cerr << "Could not initialize GLEW, error: " << glewGetErrorString(status) << std::endl;
        return false;
    }
    
    std::string glewVersion = (char *) glewGetString(GLEW_VERSION);
    std::string glVersion = (char *) glGetString(GL_VERSION);
    std::string glslVersion = (char *) glGetString(GL_SHADING_LANGUAGE_VERSION);
    std::string glExtensions = (char *) glGetString(GL_EXTENSIONS);
    
    std::string extensionString;
    std::string::iterator extensionIterator;
    for (extensionIterator = glExtensions.begin(); extensionIterator != glExtensions.end(); extensionIterator++) {
        char character = *extensionIterator;
        if (character != ' ') {
            extensionString.push_back(character);
        } else {
            extensionString.append("\n");
        }
    }
    
    std::cout << "GLEW version: " << glewVersion << std::endl;
    std::cout << "OpenGL version: " << glVersion << std::endl;
    std::cout << "GLSL version: " << glslVersion << std::endl;
    std::cout << "OpenGL extensions: " << std::endl << extensionString << std::endl;
}

void GLRenderer::doRender() {
    
    float PI = 3.14159265;
    
    rotation += 1;
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0, 0, 0, 1);
    
    int width = this->canvas->getViewport().getWidth();
    int height = this->canvas->getViewport().getHeight();
    
    float aspectRatio = (float) width / (float) height;
    
    float near = 0.0001;
    float far = 1000;
    float fov = 45 * PI / 180;
    
    float top = near * tan(fov / 2.0);
    float bottom = -top;
    float right = top * aspectRatio;
    float left = -right;
    
    
    Matrix4x4 projectionMatrix = Matrix4x4::createProjection(0.785398163, aspectRatio, 0.0001, 1000);
    Matrix4x4 projCol = Matrix4x4::createColumnMajor(projectionMatrix);
    const float *projection = projCol.get();
    
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixf(projection);
    Matrix4x4 viewMatrix = Matrix4x4::createView(Vector3D(5, rotation / 10, 10), Vector3D(0, 0, 0), Vector3D(0, 1, 0));
    Matrix4x4 viewCol = Matrix4x4::createColumnMajor(viewMatrix);
    const float *view = viewCol.get();
    
    glMatrixMode(GL_MODELVIEW);
    glLoadMatrixf(view);
    
    
    glColor4f(0, 0, 0, 1);
    glBegin(GL_LINES);
    
    glColor4f(1, 0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 0);
    
    glColor4f(0, 1, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 1, 0);
    
    glColor4f(0, 0, 1, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);
    
    glEnd();
    
    
    /*gluPerspective(45, aspectRatio, 0.0001, 1000);
    gluLookAt(0, 0, -2, 0, 0, 0, 0, 1, 0);*/
            
    
    glPushMatrix();
    glRotatef(rotation, 0, 1, 0);
    glColor4f(1,1,1,1);
    glBegin(GL_QUADS);
    glVertex3f(-0.5, 0.5, 0);
    glVertex3f(-0.5, -0.5, 0);
    glVertex3f(0.5, -0.5, 0);
    glVertex3f(0.5, 0.5, 0);
    glEnd();
    
    glPopMatrix();
}

void GLRenderer::updateViewport() {
    Viewport &viewport = this->canvas->getViewport();
    if (viewport.isDirty()) {
        glViewport(viewport.getX(), viewport.getY(), viewport.getWidth(), viewport.getHeight());
        viewport.setDirty(false);
    }
}

/*
void GLRenderer::updateVertexBuffer(RendererObject<GLuint> &rendererObject, int size, float *array) {
    GLuint vboId = rendererObject.getValue();
    std::cout << "VBO id is " << vboId << std::endl;
    if (vboId == 0) {
        glGenBuffers(1, &vboId);
        glBindBuffer(GL_ARRAY_BUFFER, vboId);
        glBufferData(GL_ARRAY_BUFFER, size, 0, GL_STREAM_DRAW);
        std::cout << "Created VBO id=" << vboId << std::endl; 
        rendererObject.setValue(vboId);
    } else {
        glBindBuffer(GL_ARRAY_BUFFER, vboId);
    }
    std::cout << "The ID is " << vboId << std::endl;
    glBufferSubData(vboId, 0, size, array);
}*/


void createVertexBuffer() {
    GLuint id = 0; // TEMP
    glGenBuffers(1, &id);
}

void deleteBuffer() {
    GLuint id = 0; // TEMP
    glDeleteBuffers(1, &id);
}
