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
    Matrix4x4 viewMatrix = Matrix4x4::createView(Vector3D(0, 0, 1), Vector3D(0, 0, 0), Vector3D(0, 1, 0));

    std::cout << "VIEW MATRIX:" << std::endl;
    std::cout << viewMatrix << std::endl;

    std::cout << "Inversed view:" << std::endl;
    optional<Matrix4x4> invert = viewMatrix.inverse();
    if (invert.valid()) {
        std::cout << *invert << std::endl;
    } else {
        std::cout << "Not inversable!" << std::endl;
    }

    program->activate();
    
    Matrix4x4 worldMatrix = scene->getTopMatrix();

    program->setMatrix4x4Uniform("projectionMatrix", projectionMatrix);
    program->setMatrix4x4Uniform("viewMatrix", viewMatrix);
    program->setMatrix4x4Uniform("worldMatrix", worldMatrix);

    int attributesFlag = POSITION | COLOR;

    program->enableAttributes(this->vertexBuffer, attributesFlag);

    renderer->renderIndexedVBO(this->vertexBuffer);

    program->disableAttributes(this->vertexBuffer, attributesFlag);

    program->deactivate();
}