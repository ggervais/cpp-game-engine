
#ifndef SPHERENODE_HPP
#define	SPHERENODE_HPP

#include "BaseSceneNode.hpp"

class SphereNode : public BaseSceneNode
{
public:
    SphereNode(std::string name, const Matrix4x4 *toMatrix, const Matrix4x4 *fromMatrix = NULL);
    SphereNode(std::string name, Effect *effect, const Matrix4x4 *toMatrix, const Matrix4x4 *fromMatrix = NULL);
    ~SphereNode();

	virtual void render(Scene *scene);
private:
    VertexBuffer vertexBuffer;
};

#endif /* SPHERENODE_HPP */