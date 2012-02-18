
#ifndef CAMERANODE_HPP
#define	CAMERANODE_HPP

#include "../Viewport.hpp"
#include "../../input/KeyboardListener.hpp"
#include "../../input/MouseMotionListener.hpp"
#include "BaseSceneNode.hpp"
#include <assert.h>

const float ONE_RADIAN = 0.01745f;
const float MIN_THETA = (float) (-PI / 2 + ONE_RADIAN);
const float MAX_THETA = (float) (PI / 2 - ONE_RADIAN);

class CameraNode : public BaseSceneNode, public KeyboardListener, public MouseMotionListener {
public:
    CameraNode(std::string name, Viewport const * const viewport, float fieldOfView, float nearClip, float farClip, const Matrix4x4 *toMatrix, const Matrix4x4 *fromMatrix = NULL);
    ~CameraNode();
    void onKeyPressed(KeyboardEvent &keyboardEvent);
    void onKeyReleased(KeyboardEvent &keyboardEvent);
    void onMouseMove(MouseMotionEvent &mouseMotionEvent);
    void update(Scene *scene, double time);
    Matrix4x4 getViewMatrix() const;
    Matrix4x4 getProjectionMatrix() const;

protected:
    float fieldOfView;
    float nearClip;
    float farClip;
    // The viewport is read-only!
    Viewport const * const viewport;
    Matrix4x4 viewMatrix;
    Matrix4x4 projectionMatrix;

    Vector3D position;
    Vector3D direction;

private:
    float theta;
    float phi;
    void clampTheta();
};

#endif /* CAMERANODE_HPP */