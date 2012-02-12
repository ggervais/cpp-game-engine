/* 
 * File:   SceneNode.hpp
 * Author: Guillaume
 *
 * Created on February 2, 2012, 7:09 PM
 */

#ifndef SCENENODE_HPP
#define	SCENENODE_HPP


#include "Scene.hpp"
#include "SceneNodeProperties.hpp"
#include "../VertexBuffer.hpp"

class Scene;

class SceneNode {
public:
    virtual void preRender(Scene* scene) = 0;
    virtual void render(Scene* scene) = 0;
    virtual void renderChildren(Scene *scene) = 0;
    virtual void postRender(Scene *scene) = 0;
    virtual void update(Scene *scene, double time) = 0;
    virtual bool isVisible(Scene *scene) const = 0;
    virtual void addChild(SceneNode *child) = 0;
	virtual const SceneNodeProperties* const get() const = 0;
	virtual void setEffect(Effect *effect) = 0;
	virtual void setParent(SceneNode *parent) = 0;
    virtual void setTransform(const Matrix4x4 *toWorld, const Matrix4x4 *fromWorld = NULL) = 0;
};

#endif	/* SCENENODE_HPP */

