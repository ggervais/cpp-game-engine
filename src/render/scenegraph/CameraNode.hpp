
#ifndef CAMERANODE_HPP
#define	CAMERANODE_HPP

#include "../Viewport.hpp"
#include "BaseSceneNode.hpp"
#include <assert.h>

class CameraNode : public BaseSceneNode {
public:
    CameraNode(std::string name, Viewport const * const viewport, float fieldOfView, float nearClip, float farClip, const Matrix4x4 *toMatrix, const Matrix4x4 *fromMatrix = NULL);
    ~CameraNode();
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
};

#endif /* CAMERANODE_HPP */