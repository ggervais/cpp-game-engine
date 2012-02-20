#include "MeshNode.hpp"
#include "CameraNode.hpp"

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

    CameraNode *camera = scene->getCamera();
    Matrix4x4 viewMatrix = camera->getViewMatrix();
    Matrix4x4 projectionMatrix = camera->getProjectionMatrix();

    program->activate();
    
    Matrix4x4 worldMatrix = scene->getTopMatrix();

    program->setIntegerUniform("useTexture", 0);
    program->setIntegerUniform("useLighting", 1);
    program->setMatrix4x4Uniform("projectionMatrix", projectionMatrix);
    program->setMatrix4x4Uniform("viewMatrix", viewMatrix);
    program->setMatrix4x4Uniform("worldMatrix", worldMatrix);

    int attributesFlag = POSITION | COLOR;

    program->enableAttributes(this->vertexBuffer, attributesFlag);

    renderer->renderIndexedVBO(this->vertexBuffer);

    program->disableAttributes(this->vertexBuffer, attributesFlag);

    program->deactivate();
}