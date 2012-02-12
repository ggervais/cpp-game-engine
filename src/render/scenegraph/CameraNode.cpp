#include "CameraNode.hpp"

CameraNode::CameraNode(std::string name, Viewport const * const viewport, float fieldOfView, float nearClip, float farClip, const Matrix4x4 *toMatrix, const Matrix4x4 *fromMatrix) :
    BaseSceneNode(name, toMatrix, fromMatrix), viewport(viewport), fieldOfView(fieldOfView), nearClip(nearClip), farClip(farClip) {
        float aspectRatio = (float) this->viewport->getWidth() / (float) this->viewport->getHeight();
        this->projectionMatrix = Matrix4x4::createProjection(this->fieldOfView, aspectRatio, this->nearClip, this->farClip);
        this->y = 0;
}

void CameraNode::update(Scene *scene, double time) {
    if (this->viewport->isDirty()) {
        float aspectRatio = (float) this->viewport->getWidth() / (float) this->viewport->getHeight();
        this->projectionMatrix = Matrix4x4::createProjection(this->fieldOfView, aspectRatio, this->nearClip, this->farClip);
    }
}

Matrix4x4 CameraNode::getViewMatrix() const {
    return get()->getFromWorldMatrix();
}

Matrix4x4 CameraNode::getProjectionMatrix() const {
    return this->projectionMatrix;
}