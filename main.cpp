/* 
 * File:   main.cpp
 * Author: Guillaume
 *
 * Created on January 16, 2012, 9:37 PM
 * 
 * The OpenGL initialization will be put into a GLRenderer class of some sort
 * later.
 * 
 * This is only a skeleton, using mostly C-style code.
 */

#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <GL/glew.h>
#include <GL/glfw.h>

#include "game/Game.hpp"
#include "ui/GLFWCanvas.hpp"
#include "timing/GLFWTimer.hpp"
#include "render/GLRenderer.hpp"
#include "input/GLFWInput.hpp"
#include "math/Vector3D.hpp"
#include "math/Matrix4x4.hpp"

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

/*
 * 
 */
int main(int argc, char* argv[]) {

    Vector3D v1(1, 2, 3);
    Vector3D v2(4, 5, 6);
    Vector3D cross = v1 * v2;
    
    std::cout << v1 << std::endl;
    std::cout << v2 << std::endl;
    std::cout << cross << std::endl;
    std::cout << v1.dot(v2) << std::endl;
    std::cout << (v1 + v2) << std::endl;
    
    Matrix4x4 m1;
    m1.set(0,0,2);
    m1.set(2,3,4);
    
    Matrix4x4 m2;
    m2.set(3,3,5);
    m2.set(2,1,9);
            
    std::cout << m1 << std::endl;
    std::cout << m2 << std::endl;
    std::cout << (m1 * m2) << std::endl;
    
    Matrix4x4 mult = m1 * m2;
    std::cout << mult.inverse() << std::endl;
    std::cout << mult.transpose() << std::endl;
    
    Matrix4x4 nonInversable;
    nonInversable.set(0,0,0);
    nonInversable.set(0,1,0);
    nonInversable.set(0,2,0);
    nonInversable.set(0,3,0);
    
    try {
        std::cout << nonInversable.inverse() << std::endl;
    } catch(int e) {
        std::cout << "Exception! " << e << std::endl;
    }
    GLFWCanvas canvas("Guillaume Gervais' C++ Game Engine", 1440, 900, false);
    GLRenderer renderer(&canvas);
    GLFWTimer timer(0.017);
    GLFWInput input;
   
    Game game(&renderer, &timer, &input);
    game.init();
    game.mainLoop();
    
    return EXIT_SUCCESS;
}

