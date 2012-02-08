#include "SceneNodeProperties.hpp"


SceneNodeProperties::SceneNodeProperties() :
	effect(NULL) 
{}

SceneNodeProperties::~SceneNodeProperties() {}

Matrix4x4 const &SceneNodeProperties::getToWorldMatrix() const {
    return this->toWorld;
}

Matrix4x4 const &SceneNodeProperties::getFromWorldMatrix() const {
    return this->fromWorld;
}

Effect const * const SceneNodeProperties::getEffect() const {
    return this->effect;
}


void SceneNodeProperties::setEffect(Effect *effect) {
    this->effect = effect;
}

void SceneNodeProperties::transform(Matrix4x4 *toWorld, Matrix4x4 *fromWorld) const {
    if (toWorld) {
        *toWorld = this->toWorld;
    }

    if (fromWorld) {
        *fromWorld = this->fromWorld;
    }
}

std::string SceneNodeProperties::getName() const {
    return this->name;
}

float SceneNodeProperties::getRadius() const {
    return this->radius;
}
