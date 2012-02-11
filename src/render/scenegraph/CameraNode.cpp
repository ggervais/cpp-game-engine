#include "CameraNode.hpp"

void CameraNode::update(Scene *scene, double time) {
    if (this->viewport->isDirty()) {
        float aspectRatio = (float) this->viewport->getWidth() / (float) this->viewport->getHeight();
        this->projectionMatrix = Matrix4x4::createProjection(this->fieldOfView, aspectRatio, this->near, this->far);
    }
}

Matrix4x4 CameraNode::getViewMatrix() const {
    return this->viewMatrix;
}

Matrix4x4 CameraNode::getProjectionMatrix() const {
    return this->projectionMatrix;
}