#include "CameraNode.hpp"

float t = 0;

CameraNode::~CameraNode() {
}

CameraNode::CameraNode(std::string name, Viewport const * const viewport, float fieldOfView, float nearClip, float farClip, const Matrix4x4 *toMatrix, const Matrix4x4 *fromMatrix) :
    BaseSceneNode(name, toMatrix, fromMatrix), viewport(viewport), fieldOfView(fieldOfView), nearClip(nearClip), farClip(farClip) {

        float aspectRatio = (float) this->viewport->getWidth() / (float) this->viewport->getHeight();
        this->projectionMatrix = Matrix4x4::createProjection(this->fieldOfView, aspectRatio, this->nearClip, this->farClip);
        this->position = toMatrix->getPosition();
        this->theta = 0;
        this->phi = 0;
        this->direction = Vector3D(0, 0, -1);
        this->right = Vector3D(1, 0, 0);
        this->up = Vector3D(0, 1, 0);
        this->bob = 0;
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

    float k = 0.1;
    Vector3D velocity;

    switch (key) {
        case W:
            velocity += this->direction * -k;
            break;
            
        case A:
            velocity += this->right * k;
            break;
            
        case S:
            velocity += this->direction * k;
            break;

        case D:
            velocity += this->right * -k;
            break;
    }

    Vector3D realUp = this->right * this->direction;

    
    this->bob += 20 * 0.0174532925;

    velocity += realUp * (0.01 * sin(this->bob));

    this->position += velocity;

}

void CameraNode::onKeyReleased(KeyboardEvent &keyboardEvent) {
    Key key = keyboardEvent.getKey();
}

void CameraNode::clampTheta() {
    if (this->theta < MIN_THETA) {
		this->theta = MIN_THETA;
	}
	if (this->theta > MAX_THETA) {
		this->theta = MAX_THETA;
	}    
}

void CameraNode::onMouseMove(MouseMotionEvent &mouseMotionEvent) {
    
    int diffX = mouseMotionEvent.getDiffX();
    int diffY = mouseMotionEvent.getDiffY();

    // Damp the movement.
    this->phi += diffX * 0.005;
    this->theta += diffY * 0.005;
		
	clampTheta();

    // YAW PITCH ROLL
    // Y    X    Z

    //theta = 0;
    //phi = 0;

    //phi = 0;
    //theta = PI / 4;

    float phiToUseInConversion = this->phi + PI / 2;
    float minusTheta = -this->theta;

    std::cout << (phi * 180 / PI) << " " << (minusTheta * 180 / PI) << std::endl;

    

    float rotationX = (float) cos(minusTheta) * (float) cos(phiToUseInConversion);
    float rotationY = (float) sin(minusTheta);
    float rotationZ = (float) cos(minusTheta) * sin(phiToUseInConversion);
    //this->phi += 0.01745;
    
    this->direction = Vector3D(rotationX, rotationY, rotationZ).normalized();
    this->right = (this->direction * this->up).normalized();

    std::cout << this->direction << " " << this->right << std::endl;


    Matrix4x4 transformMatrix = Matrix4x4::createRotationFromXYZ(theta, -phi, 0);
    transformMatrix.setPosition(this->position);
    setTransform(&transformMatrix);
}