#include "BaseSceneNode.hpp"


BaseSceneNode::BaseSceneNode(std::string name, const Matrix4x4 *toMatrix, const Matrix4x4 *fromMatrix) {
    this->parent = NULL;
    this->properties.name = name;
    setTransform(toMatrix, fromMatrix);
}


BaseSceneNode::~BaseSceneNode(void)
{
}

void BaseSceneNode::setTransform(const Matrix4x4 *toMatrix, const Matrix4x4 *fromMatrix) {
    this->properties.toWorld = *toMatrix;
    if (fromMatrix) {
        this->properties.fromWorld = *fromMatrix;
    } else {
        optional<Matrix4x4> inverseOfToMatrix = this->properties.toWorld.inverse();
        assert(inverseOfToMatrix.valid());
        this->properties.fromWorld = *inverseOfToMatrix;
    }
}

const SceneNodeProperties* const BaseSceneNode::get() const {
    return &this->properties;
}

void BaseSceneNode::setRadius(float radius) {
    this->properties.radius = radius;
}

void BaseSceneNode::setEffect(Effect *effect) {
    this->properties.effect = effect;
}

void BaseSceneNode::preRender(Scene *scene, Renderer *renderer) {
    scene->pushAndSetMatrix(this->properties.toWorld);
}

void BaseSceneNode::postRender(Scene *scene, Renderer *renderer) {
    scene->popMatrix();
}

void BaseSceneNode::update(Scene *scene, double time) {
    for (SceneNodeList::iterator it = children.begin(); it != children.end(); it++) {
        (*it)->update(scene, time);
    }
}