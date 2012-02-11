
#ifndef CAMERANODE_HPP
#define	CAMERANODE_HPP

#include "../Viewport.hpp"
#include "BaseSceneNode.hpp"
#include <assert.h>

typedef std::vector<SceneNode*> BaseSceneNodeList;

class CameraNode : public SceneNode
{

public:
    CameraNode(std::string name, Viewport const * const viewport, float fieldOfView, float near, float far, const Matrix4x4 *toMatrix, const Matrix4x4 *fromMatrix = NULL);
    ~CameraNode();
    void update(Scene *scene, double time);
    Matrix4x4 getViewMatrix() const;
    Matrix4x4 getProjectionMatrix() const;

protected:
    float fieldOfView;
    float near;
    float far;
    // The viewport is read-only!
    Viewport const * const viewport;
    Matrix4x4 viewMatrix;
    Matrix4x4 projectionMatrix;
};

#endif /* CAMERANODE_HPP */