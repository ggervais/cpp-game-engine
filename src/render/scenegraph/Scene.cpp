#include "Scene.hpp"
#include "BaseSceneNode.hpp"


Scene::Scene(Renderer *renderer) {
	this->renderer = renderer;
	Matrix4x4 identity = Matrix4x4::createIdentity();
	this->root = new BaseSceneNode("Root node", &identity);
}

Scene::~Scene() {
	delete this->root;
}

void Scene::pushAndSetMatrix(Matrix4x4 &matrix) {
	
	Matrix4x4 topMatrix = Matrix4x4::createIdentity();
	if (this->matrixStack.size() > 0) {
		topMatrix = this->matrixStack.top();		
	}

	Matrix4x4 multiplied = topMatrix * matrix;
	this->matrixStack.push(multiplied);
	std::cout << "pushAndSetMatrix() called, nb. matrices=" << this->matrixStack.size() << std::endl;
}

void Scene::popMatrix() {
	this->matrixStack.pop();
	std::cout << "popMatrix() called, nb. matrices=" << this->matrixStack.size() << std::endl;
}

Effect* Scene::getEffect(std::string name) {
	return this->effects[name];
}

void Scene::setCamera(CameraNode *camera) {
	this->camera = camera;
}

CameraNode *Scene::getCamera() {
	return this->camera;
}

void Scene::addChild(SceneNode *child) {
	this->root->addChild(child);
}

void Scene::update(double time) {
	std::cout << "Rendering scene at time=" << time << std::endl;
	this->root->update(this, time);
}

void Scene::render() {
	this->root->preRender(this);
	this->root->render(this);
	this->root->renderChildren(this);
	this->root->postRender(this);
}