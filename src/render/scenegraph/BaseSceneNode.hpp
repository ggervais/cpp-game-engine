
#ifndef BASESCENENODE_HPP
#define	BASESCENENODE_HPP

#include "SceneNode.hpp"
#include "SceneNodeProperties.hpp"
#include <assert.h>

typedef std::vector<SceneNode*> SceneNodeList;

class BaseSceneNode : public SceneNode
{
    friend class Scene;

public:
    BaseSceneNode(std::string name, const Matrix4x4 *toMatrix, const Matrix4x4 *fromMatrix = NULL);
    ~BaseSceneNode();
    virtual void setTransform(const Matrix4x4 *toMatrix, const Matrix4x4 *fromMatrix);
    virtual const SceneNodeProperties* const get() const;
    void setRadius(float radius);
    void setEffect(Effect *effect);

    virtual void preRender(Scene *scene, Renderer *renderer);
    virtual void postRender(Scene *scene, Renderer *renderer);
    virtual void update(Scene *scene, double time);


protected:
    SceneNodeList children;
    BaseSceneNode *parent;
    SceneNodeProperties properties;
};

#endif /* BASESCENENODE_HPP */