#include "SphereNode.hpp"
#include "CameraNode.hpp"

SphereNode::SphereNode(std::string name, const Matrix4x4 *toMatrix, const Matrix4x4 *fromMatrix) 
    : BaseSceneNode(name, toMatrix, fromMatrix) {
        this->properties.setEffect(NULL);

        Vertex v;
        v.x = 0;
        v.y = 0;
        v.z = 0;

        this->vertexBuffer.addVertex(v);
        this->vertexBuffer.addIndex(0);
        
}

SphereNode::~SphereNode() {
}

SphereNode::SphereNode(std::string name, Effect *effect, const Matrix4x4 *toMatrix, const Matrix4x4 *fromMatrix) :
   BaseSceneNode(name, toMatrix, fromMatrix) {
       this->properties.setEffect(effect);
}

void SphereNode::render(Scene *scene) {

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

    program->setMatrix4x4Uniform("projectionMatrix", projectionMatrix);
    program->setMatrix4x4Uniform("viewMatrix", viewMatrix);
    program->setMatrix4x4Uniform("worldMatrix", worldMatrix);

    int attributesFlag = POSITION;

    program->enableAttributes(this->vertexBuffer, attributesFlag);

    renderer->renderIndexedVBO(this->vertexBuffer, PRIMITIVE_POINT);

    program->disableAttributes(this->vertexBuffer, attributesFlag);

    program->deactivate();
}