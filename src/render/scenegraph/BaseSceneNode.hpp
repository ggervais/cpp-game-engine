
#ifndef BASESCENENODE_HPP
#define	BASESCENENODE_HPP

#include "SceneNode.hpp"
#include <assert.h>

typedef std::vector<SceneNode*> SceneNodeList;

class BaseSceneNode : public SceneNode
{
    friend class Scene;

public:
    BaseSceneNode(std::string name, const Matrix4x4 *toMatrix, const Matrix4x4 *fromMatrix = NULL);
    ~BaseSceneNode();

    virtual void setTransform(const Matrix4x4 *toMatrix, const Matrix4x4 *fromMatrix);
    
    void setRadius(float radius);
    void setEffect(Effect *effect);

	virtual const SceneNodeProperties* const get() const;
    virtual void preRender(Scene *scene);
    virtual void postRender(Scene *scene);
    virtual void update(Scene *scene, double time);
	virtual void render(Scene *scene);
    virtual void renderChildren(Scene *scene);
	virtual void addChild(SceneNode *child);
	virtual bool isVisible(Scene *scene) const;
	virtual void setParent(SceneNode *parent);


protected:
    SceneNodeList children;
    SceneNode *parent;
    SceneNodeProperties properties;
};

#endif /* BASESCENENODE_HPP */