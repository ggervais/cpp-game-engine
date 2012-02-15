#include "BaseSceneNode.hpp"


BaseSceneNode::BaseSceneNode(std::string name, const Matrix4x4 *toMatrix, const Matrix4x4 *fromMatrix) :
	  parent(NULL) {
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
        if (inverseOfToMatrix.valid()) {
            this->properties.fromWorld = *inverseOfToMatrix;
        }
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
	
	for (SceneNodeList::iterator it = this->children.begin(); it != this->children.end(); it++) {
		SceneNode *child = *it;
		if (!child->get()->effect) {
			std::cout << "Setting effect for " << child->get()->name << std::endl;
			child->setEffect(effect);
		}
	}
}

void BaseSceneNode::preRender(Scene *scene) {
	//std::cout << "Called preRender() for " << this->properties.name << std::endl;
    scene->pushAndSetMatrix(this->properties.toWorld);
}

void BaseSceneNode::render(Scene *scene) {
	// TODO check for alpha and materials.
	//std::cout << "Called render() for " << this->properties.name << std::endl;
}

void BaseSceneNode::renderChildren(Scene *scene) {
	//std::cout << "Called renderChildren() for " << this->properties.name << std::endl;
	// Iterate through all child nodes.
	for (SceneNodeList::iterator it = children.begin(); it != children.end(); it++) {
		SceneNode *child = *it;
		
		child->preRender(scene);

		if (child->isVisible(scene)) {
			// TODO check for alpha
			child->render(scene);
		}
		
		// TODO check if visibility check for parent yields the same result for children.
		// In that case we could put the renderChildren() call in the isVisible() condition.
		child->renderChildren(scene);
		child->postRender(scene);
	}
}

void BaseSceneNode::postRender(Scene *scene) {
	//std::cout << "Called postRender() for " << this->properties.name << std::endl;
    scene->popMatrix();
}

void BaseSceneNode::update(Scene *scene, double time) {
	//std::cout << "Called update() for " << this->properties.name << std::endl;
    for (SceneNodeList::iterator it = this->children.begin(); it != this->children.end(); it++) {
        SceneNode *child = *it;
		child->update(scene, time);
    }
}

void BaseSceneNode::setParent(SceneNode *parent) {
	this->parent = parent;
}

void BaseSceneNode::addChild(SceneNode *child) {
	std::cout << "Called addChild() for " << this->properties.name << std::endl;
	this->children.push_back(child);
	child->setParent(this);

	Vector3D childPosition = child->get()->getToWorldMatrix().getPosition();
	Vector3D direction = childPosition - this->properties.toWorld.getPosition();
	float newRadius = direction.length() + child->get()->getRadius();
	if (newRadius > this->properties.radius) {
		this->properties.radius = newRadius;
	}
	if (this->properties.effect && !child->get()->effect) {
		std::cout << "Adding effect for " << child->get()->name << std::endl;
		child->setEffect(this->properties.effect);
	}
}

bool BaseSceneNode::isVisible(Scene *scene) const {
	//std::cout << "Called isVisible() for " << this->properties.name << std::endl;
	return true;
}