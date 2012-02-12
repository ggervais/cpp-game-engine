
#ifndef SCENE_HPP
#define	SCENE_HPP

#include "../../math/Matrix4x4.hpp"
#include "../Renderer.hpp"
#include "../Effect.hpp"

#include <stack>
#include <map>

class CameraNode;
class SceneNode;

// TODO put this into a real class named EffectManager.
typedef std::map<std::string, Effect*> EffectManager;

class Scene
{
public:
    Scene(Renderer *renderer);
    ~Scene(void);
    void pushAndSetMatrix(Matrix4x4 &matrix);
    void popMatrix();
    Matrix4x4 getTopMatrix();
	Effect *getEffect(std::string name);
	void setCamera(CameraNode *camera);
    CameraNode *getCamera();
	void addChild(SceneNode *child);
	void render();
	void update(double time);
    Renderer *getRenderer() const;

protected:
	CameraNode *camera;
	SceneNode *root; // Maybe BaseSceneNode could work too.
	std::stack<Matrix4x4> matrixStack;
    Renderer *renderer;
	EffectManager effects;
};

#endif /* SCENE_HPP */