
#ifndef SCENENODEPROPERTIES_HPP
#define	SCENENODEPROPERTIES_HPP

#include <iostream>
#include <string>

#include "SceneNode.hpp"
#include "../Effect.hpp"
#include "../../math/Matrix4x4.hpp"

class SceneNodeProperties
{
    friend class BaseSceneNode;
public:
    SceneNodeProperties();
    ~SceneNodeProperties();

    Matrix4x4 const &getToWorldMatrix() const;
    Matrix4x4 const &getFromWorldMatrix() const;
    void transform(Matrix4x4 *toWorld, Matrix4x4 *fromWorld) const;
    std::string getName() const;
    float getRadius() const;

private:
    std::string name;       // The name of the node.
    Matrix4x4 toWorld;      // This matrix converts from local space to world space.
    Matrix4x4 fromWorld;    // This matrix converts from world space to local space.
    float radius;           // The radius of the node's bounding sphere (if any).
    // Material?
    Effect *effect;         // The effect for this node. This is basically a shader program that is set recursively through child nodes.
};

#endif /* SCENENODEPROPERTIES_HPP */