#include "MeshNode.hpp"

MeshNode::MeshNode(std::string name, const Matrix4x4 *toMatrix, const Matrix4x4 *fromMatrix) 
    : BaseSceneNode(name, toMatrix, fromMatrix) {
        this->properties.setEffect(NULL);
        
}

MeshNode::~MeshNode() {
}

MeshNode::MeshNode(std::string name, Effect *effect, const Matrix4x4 *toMatrix, const Matrix4x4 *fromMatrix) :
   BaseSceneNode(name, toMatrix, fromMatrix) {
       this->properties.setEffect(effect);
}

VertexBuffer &MeshNode::getVertexBuffer() {
    return this->vertexBuffer;
}

void MeshNode::render(Scene *scene) {
    Renderer *renderer = scene->getRenderer();
    if (!this->vertexBuffer.isInitialized()) {
        renderer->createVertexBuffer(this->vertexBuffer);
        renderer->updateVertexBufferData(this->vertexBuffer);
    }
    Program *program = this->properties.getEffect()->getProgram();

    // TEMP create matrices
    int width = 1440;
    int height = 900;
    
    float aspectRatio = (float) width / (float) height;
    
    float near = 0.0001f;
    float far = 1000.0f;
    float fov = 45 * PI / 180.0f;
    
    Matrix4x4 projectionMatrix = Matrix4x4::createProjection(fov, aspectRatio, near, far);
    Matrix4x4 viewMatrix = Matrix4x4::createView(Vector3D(5, 10, 10), Vector3D(0, 0, 0), Vector3D(0, 1, 0));

    program->activate();
    
    program->setMatrix4x4Uniform("projectionMatrix", projectionMatrix);
    program->setMatrix4x4Uniform("modelViewMatrix", viewMatrix);

    int attributesFlag = POSITION | COLOR;

    program->enableAttributes(this->vertexBuffer, attributesFlag);

    renderer->renderIndexedVBO(this->vertexBuffer);

    program->disableAttributes(this->vertexBuffer, attributesFlag);

    program->deactivate();
}