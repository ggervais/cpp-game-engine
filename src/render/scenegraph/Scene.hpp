
#ifndef SCENE_HPP
#define	SCENE_HPP

#include <iostream>
#include "../../math/Matrix4x4.hpp"

class Scene
{
public:
    Scene(void);
    ~Scene(void);
    void pushAndSetMatrix(Matrix4x4 matrix);
    void popMatrix();
private:
};

#endif /* SCENE_HPP */