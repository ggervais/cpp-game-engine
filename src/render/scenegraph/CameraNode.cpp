#include "CameraNode.hpp"

float t = 0;

CameraNode::~CameraNode() {
}

CameraNode::CameraNode(std::string name, Viewport const * const viewport, float fieldOfView, float nearClip, float farClip, const Matrix4x4 *toMatrix, const Matrix4x4 *fromMatrix) :
    BaseSceneNode(name, toMatrix, fromMatrix), viewport(viewport), fieldOfView(fieldOfView), nearClip(nearClip), farClip(farClip) {
        float aspectRatio = (float) this->viewport->getWidth() / (float) this->viewport->getHeight();
        this->projectionMatrix = Matrix4x4::createProjection(this->fieldOfView, aspectRatio, this->nearClip, this->farClip);
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
    toWorld.set(2, 3, toWorld.get(2, 3) - 0.001);
    //setTransform(&toWorld);
    t += 0.05;
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
    Vector3D position = toWorld.getPosition();
    Vector3D oldPosition = position;

    switch (key) {
        case W:
            position.z(position.z() - 0.1);
        break;
            
        case A:
            position.x(position.x() - 0.1);
            break;
            
        case S:
            position.z(position.z() + 0.1);
            break;

        case D:
            position.x(position.x() + 0.1);
            break;
    }

    toWorld.setPosition(position);
    setTransform(&toWorld);
    
}

void CameraNode::onKeyReleased(KeyboardEvent &keyboardEvent) {
    Key key = keyboardEvent.getKey();
}