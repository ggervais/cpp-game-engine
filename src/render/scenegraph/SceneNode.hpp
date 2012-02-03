/* 
 * File:   SceneNode.hpp
 * Author: Guillaume
 *
 * Created on February 2, 2012, 7:09 PM
 */

#ifndef SCENENODE_HPP
#define	SCENENODE_HPP

#include "../Renderer.hpp"
#include "Scene.hpp"

class SceneNode {
public:
    virtual void preRender(Scene *scene, Renderer *renderer) = 0;
    virtual void render(Scene *scene, Renderer *renderer) = 0;
    virtual void renderChildren(Scene *scene, Renderer *renderer) = 0;
    virtual void postRender(Scene *scene, Renderer *renderer) = 0;
    virtual void update(Scene *scene, double time) = 0;
    virtual bool isVisible(Scene *scene) const = 0;
    virtual void addChild(SceneNode *child) = 0;
};

#endif	/* SCENENODE_HPP */

