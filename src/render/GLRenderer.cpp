/* 
 * File:   GLRenderer.cpp
 * Author: Guillaume
 * 
 * Created on January 18, 2012, 11:18 PM
 */

#include "GLRenderer.hpp"
#include "RendererObject.hpp"
#include "GLRendererObject.hpp"

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
   // std::cout << "OpenGL extensions: " << std::endl << extensionString << std::endl;

    glEnable(GL_DEPTH_TEST);

	return true;
}

void GLRenderer::clearScreen() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0, 0, 0, 1);
}

void GLRenderer::renderIndexedVBO(VertexBuffer &vertexBuffer) {
    
    RendererObject *vbo = vertexBuffer.getVBOHandle();
    GLuint vboId = *((GLuint*) vbo->getValue());
    
    RendererObject *ibo = vertexBuffer.getIBOHandle();
    GLuint iboId = *((GLuint*) ibo->getValue());

    GLint currentlyBoundVBO = 0;
    glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &currentlyBoundVBO);

    if (currentlyBoundVBO != vboId) {
        glBindBuffer(GL_ARRAY_BUFFER, vboId);
    }
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboId);
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, NULL);
    
}

void GLRenderer::doRender(VertexBuffer &vertexBuffer) {
    
    /*
    float PI = 3.14159265f;
    
    rotation += 1;
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0, 0, 0, 1);
    
    int width = this->canvas->getViewport().getWidth();
    int height = this->canvas->getViewport().getHeight();
    
    float aspectRatio = (float) width / (float) height;
    
    float near = 0.0001f;
    float far = 1000.0f;
    float fov = 45 * PI / 180.0f;
    
    float top = near * tan(fov / 2.0f);
    float bottom = -top;
    float right = top * aspectRatio;
    float left = -right;
    
    
    Matrix4x4 projectionMatrix = Matrix4x4::createProjection(0.785398163f, aspectRatio, 0.0001f, 1000.0f);
    Matrix4x4 projCol = Matrix4x4::createColumnMajor(projectionMatrix);
    const float *projection = projCol.get();
    
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixf(projection);
    
    Matrix4x4 viewMatrix = Matrix4x4::createView(Vector3D(5, 10, 10), Vector3D(0, 0, 0), Vector3D(0, 1, 0));
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
    
    RendererObject *vbo = vertexBuffer.getVBOHandle();
    GLuint vboId = *((GLuint*) vbo->getValue());
    
    RendererObject *ibo = vertexBuffer.getIBOHandle();
    GLuint iboId = *((GLuint*) ibo->getValue());    
    
    std::cout << "Renderer VBO ID: " << vboId << ", Size " << vertexBuffer.getVBOSize() << std::endl; 
    std::cout << "Renderer IBO ID: " << iboId << ", Size " << vertexBuffer.getIBOSize() << std::endl;
    
    
    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);
    
    glBindBuffer(GL_ARRAY_BUFFER, vboId);
    
    glVertexPointer(3, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(0));
    glColorPointer(4, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(sizeof(float) * 3));
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboId);
    
    glRotatef(rotation, 0, 1, 0);
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, NULL);
    
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    */
    /*gluPerspective(45, aspectRatio, 0.0001, 1000);
    gluLookAt(0, 0, -2, 0, 0, 0, 0, 1, 0);*/
            
    /*
    glPushMatrix();
    glRotatef(rotation, 0, 1, 0);
    glColor4f(1,1,1,1);
    glBegin(GL_QUADS);
    glVertex3f(-0.5, 0.5, 0);
    glVertex3f(-0.5, -0.5, 0);
    glVertex3f(0.5, -0.5, 0);
    glVertex3f(0.5, 0.5, 0);
    glEnd();
    
    glPopMatrix();*/
}

void GLRenderer::updateViewport() {
    Viewport &viewport = this->canvas->getViewport();
    if (viewport.isDirty()) {
        glViewport(viewport.getX(), viewport.getY(), viewport.getWidth(), viewport.getHeight());
        viewport.setDirty(false);
    }
}

void GLRenderer::createVertexBuffer(VertexBuffer &buffer) {
    
    GLuint vboId = 0;
    
    glGenBuffers(1, &vboId);
    glBindBuffer(GL_ARRAY_BUFFER, vboId);
    glBufferData(GL_ARRAY_BUFFER, buffer.getVBOSize() * sizeof(Vertex), NULL, GL_STREAM_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    RendererObject *vbo = new GLRendererObject();
    vbo->setValue(&vboId);
    buffer.setVBOHandle(vbo);
    
    
    GLuint iboId = 0;
    glGenBuffers(1, &iboId);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, buffer.getIBOSize() * sizeof(unsigned int), NULL, GL_STREAM_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    
    RendererObject *ibo = new GLRendererObject();
    ibo->setValue(&iboId);
    buffer.setIBOHandle(ibo);
    
    std::cout << "Created VBO with id " << vboId << " and IBO with id " << iboId << std::endl;
}


void GLRenderer::updateVertexBufferData(VertexBuffer &buffer) {
    
    if (buffer.isVBODirty() && buffer.getVBOSize() > 0) {
        RendererObject *object = buffer.getVBOHandle();
        GLuint vboId = *((GLuint*) object->getValue());

        if (vboId > 0) {
            std::cout << "VBO id is " << vboId << std::endl;
            glBindBuffer(GL_ARRAY_BUFFER, vboId);
            glBufferData(GL_ARRAY_BUFFER, buffer.getVBOSize() * sizeof(Vertex), buffer.getVBOData(), GL_STREAM_DRAW);
            glBindBuffer(GL_ARRAY_BUFFER, 0);
        }
        buffer.setVBODirty(false);
    }
    
    if (buffer.isIBODirty() && buffer.getIBOSize() > 0) {
        RendererObject *object = buffer.getIBOHandle();
        GLuint iboId = *((GLuint*) object->getValue());

        
        if (iboId > 0) {
            std::cout << "IBO id is " << iboId << ", size " << buffer.getIBOSize() * sizeof(unsigned int) << std::endl;
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboId);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, buffer.getIBOSize() * sizeof(unsigned int), buffer.getIBOData(), GL_STREAM_DRAW);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        }
        buffer.setIBODirty(false);
    }
}

void GLRenderer::deleteVertexBuffer(VertexBuffer &buffer) {
    
    
    // Delete vertex buffer.
    RendererObject *vboObject = buffer.getVBOHandle();
    GLuint vboId = *((GLuint*) vboObject->getValue());
    
    std::cout << "Deleting VBO with id " << vboId << std::endl;
    
    if (vboId > 0) {
        glDeleteBuffers(1, &vboId);
    }
    
    std::cout << "VBO Buffer deleted on GPU";
    
    delete vboObject;
    
    // Delete index buffer.
    RendererObject *iboObject = buffer.getIBOHandle();
    GLuint iboId = *((GLuint*) iboObject->getValue());
    
    std::cout << "Deleting IBO with id " << iboId << std::endl;
    
    if (iboId > 0) {
        glDeleteBuffers(1, &iboId);
    }
    
    delete iboObject;
    
    std::cout << "Deleted VBO with id " << vboId << " and IBO with id " << iboId << std::endl;
}


Shader *GLRenderer::createShader(ShaderType type, std::string filename) {
    return new GLShader(type, filename);
}

void GLRenderer::deleteShader(Shader *shader) {
    delete shader;
}

Program *GLRenderer::createProgram(Shader *vertexShader, Shader *fragmentShader) {
    return new GLProgram(vertexShader, fragmentShader);
}

void GLRenderer::deleteProgram(Program *program) {
    delete program;
}