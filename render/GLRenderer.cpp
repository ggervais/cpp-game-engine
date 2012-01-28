/* 
 * File:   GLRenderer.cpp
 * Author: Guillaume
 * 
 * Created on January 18, 2012, 11:18 PM
 */

#include "GLRenderer.hpp"

float rotation;

GLRenderer::GLRenderer(Canvas *canvas) :
        Renderer(canvas)
{}

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
    
    rotation += 1;
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1, 0, 1, 1);
    
    int width = this->canvas->getViewport().getWidth();
    int height = this->canvas->getViewport().getHeight();
    
    float aspectRatio = (float) width / (float) height;
    
            
    Matrix4x4 projectionMatrix = Matrix4x4::createProjection(0.785398163, aspectRatio, 0.0001, 1000);
    Matrix4x4 projCol = Matrix4x4::createColumnMajor(projectionMatrix);
    const float *projection = projCol.get();
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMultMatrixf(projection);
    
    
    Matrix4x4 viewMatrix = Matrix4x4::createView(Vector3D(0, 0, 10), Vector3D(0, 0, 0), Vector3D(0, 1, 0));
    Matrix4x4 viewCol = Matrix4x4::createColumnMajor(viewMatrix);
    const float *view = viewCol.get();
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glMultMatrixf(view);
    
    
    glColor4f(0, 0, 0, 1);
    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 0);
    glEnd();
    
    /*gluPerspective(45, aspectRatio, 0.0001, 1000);
    gluLookAt(0, 0, -2, 0, 0, 0, 0, 1, 0);*/
            
    
    glRotatef(rotation, 0, 1, 0);
    glColor4f(1,1,1,1);
    glBegin(GL_QUADS);
    glVertex3f(-0.5, 0.5, 0);
    glVertex3f(-0.5, -0.5, 0);
    glVertex3f(0.5, -0.5, 0);
    glVertex3f(0.5, 0.5, 0);
    glEnd();
}

void GLRenderer::updateViewport() {
    Viewport &viewport = this->canvas->getViewport();
    if (viewport.isDirty()) {
        glViewport(viewport.getX(), viewport.getY(), viewport.getWidth(), viewport.getHeight());
        viewport.setDirty(false);
    }
}

