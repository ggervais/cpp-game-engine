#include "CameraNode.hpp"

float t = 0;

CameraNode::~CameraNode() {
}

CameraNode::CameraNode(std::string name, Viewport const * const viewport, float fieldOfView, float nearClip, float farClip, const Matrix4x4 *toMatrix, const Matrix4x4 *fromMatrix) :
    BaseSceneNode(name, toMatrix, fromMatrix), viewport(viewport), fieldOfView(fieldOfView), nearClip(nearClip), farClip(farClip) {

        float aspectRatio = (float) this->viewport->getWidth() / (float) this->viewport->getHeight();
        this->projectionMatrix = Matrix4x4::createProjection(this->fieldOfView, aspectRatio, this->nearClip, this->farClip);
        this->position = toMatrix->getPosition();
}

void CameraNode::update(Scene *scene, double time) {
    if (this->viewport->isDirty()) {
        float aspectRatio = (float) this->viewport->getWidth() / (float) this->viewport->getHeight();
        this->projectionMatrix = Matrix4x4::createProjection(this->fieldOfView, aspectRatio, this->nearClip, this->farClip);
    }

    Matrix4x4 toWorld = this->properties.getToWorldMatrix();
    /*toWorld.set(0, 3, toWorld.get(0, 3) - 0.1 * sin(0.5*t));
    toWorld.set(1, 3, toWorld.get(1, 3) - 0.1 * sin(0.5*t));*/
    //toWorld.set(2, 3, toWorld.get(2, 3) - 0.1 * sin(0.5*t));
    toWorld.setPosition(this->position);
    setTransform(&toWorld);
}

Matrix4x4 CameraNode::getViewMatrix() const {
    return get()->getFromWorldMatrix();
}

Matrix4x4 CameraNode::getProjectionMatrix() const {
    return this->projectionMatrix;
}

void CameraNode::onKeyPressed(KeyboardEvent &keyboardEvent) {

    Key key = keyboardEvent.getKey();
    Matrix4x4 toWorld = this->properties.getToWorldMatrix();

    switch (key) {
        case W:
            this->position.z(this->position.z() - 0.1);
        break;
            
        case A:
            this->position.x(this->position.x() - 0.1);
            break;
            
        case S:
            this->position.z(this->position.z() + 0.1);
            break;

        case D:
            this->position.x(this->position.x() + 0.1);
            break;
    }
    
}

void CameraNode::onKeyReleased(KeyboardEvent &keyboardEvent) {
    Key key = keyboardEvent.getKey();
}

void CameraNode::onMouseMove(MouseMotionEvent &mouseMotionEvent) {
    std::cout << "onMouseMove in CameraNode, x " << mouseMotionEvent.getDiffX() << " y " << mouseMotionEvent.getDiffY() << std::endl;
}