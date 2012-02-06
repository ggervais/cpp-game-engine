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

#include "game/Game.hpp"
#include "render/GLRenderer.hpp"
#include "ui/GLFWCanvas.hpp"
#include "timing/GLFWTimer.hpp"
#include "input/GLFWInput.hpp"
#include "math/Vector3D.hpp"
#include "math/Matrix4x4.hpp"
#include "render/scenegraph/Scene.hpp"
#include "render/scenegraph/BaseSceneNode.hpp"
#include "render/GLShader.hpp"

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
    optional<Matrix4x4> inverse = mult.inverse();
    if (inverse.valid()) {
        std::cout << *inverse << std::endl;
    }
    std::cout << mult.transpose() << std::endl;
    
    Matrix4x4 nonInversable;
    nonInversable.set(0,0,0);
    nonInversable.set(0,1,0);
    nonInversable.set(0,2,0);
    nonInversable.set(0,3,0);
    
    optional<Matrix4x4> inverseSafe = nonInversable.inverse();
    std::cout << "Is valid? " << inverseSafe.valid() << std::endl;
    
    Matrix4x4 projection = Matrix4x4::createProjection(4.0/3.0f, 0.785398163, 1.0, 1000.0);
    std::cout << "Own projection: " << std::endl << projection << std::endl;
    
    Vector3D eye(1, 1, 0);
    Vector3D lookAt(0, 0, 0);
    Vector3D up(0, 1, 0);
    
    Matrix4x4 view = Matrix4x4::createView(eye, lookAt, up);
    std::cout << "Own view: " << std::endl << view << std::endl;
    std::cout << 22/5*3 << std::endl;
    
    optional<int> value = 10;
    std::cout << "Optional value is " << *value << std::endl;
    
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	
    Canvas *canvas = new GLFWCanvas("Guillaume Gervais' C++ Game Engine", 1440, 900, false);
    Renderer *renderer = new GLRenderer(canvas);
    Timer *timer = new GLFWTimer(0.017);
    Input * input = new GLFWInput();

	Scene scene(renderer);
	
	Matrix4x4 identity = Matrix4x4::createIdentity();
	BaseSceneNode node1("Node1", &identity);
	BaseSceneNode node2("Node2", &identity);
	BaseSceneNode node3("Node3", &identity);
	BaseSceneNode node4("Node4", &identity);
	
	Effect effect;
	node2.setEffect(&effect);
	

	scene.addChild(&node1);
	scene.addChild(&node2);
	node2.addChild(&node3);
	node2.addChild(&node4);

	scene.update(timer->getTime());
	scene.render();

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

    
    /*Shader *shader = new GLShader(VERTEX_SHADER, "hello-gl.v.glsl");
    shader->compile();
    delete shader;*/

   
    Game game(renderer, timer, input);
    game.init();
    game.mainLoop();
    game.dispose();
    delete input;
    delete timer;
    delete canvas;
    delete renderer;
    
    std::cout << "Deleted all objects." << std::endl;
	std::string t;
	std::cin >> t;


    return EXIT_SUCCESS;
}

