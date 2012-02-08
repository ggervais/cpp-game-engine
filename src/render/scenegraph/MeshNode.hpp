
#ifndef MESHNODE_HPP
#define	MESHNODE_HPP

#include "BaseSceneNode.hpp"

class MeshNode : public BaseSceneNode
{
public:
    MeshNode(std::string name, const Matrix4x4 *toMatrix, const Matrix4x4 *fromMatrix = NULL);
    MeshNode(std::string name, Effect *effect, const Matrix4x4 *toMatrix, const Matrix4x4 *fromMatrix = NULL);
    ~MeshNode();

    VertexBuffer &getVertexBuffer();

	virtual void render(Scene *scene);
private:
    VertexBuffer vertexBuffer;
};

#endif /* MESHNODE_HPP */