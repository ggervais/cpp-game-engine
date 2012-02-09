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
#include "render/scenegraph/MeshNode.hpp"
#include "render/GLShader.hpp"
#include "render/GLProgram.hpp"

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

/*
 * 
 */
int main(int argc, char* argv[]) {

    // Setup base objects
    Canvas *canvas = new GLFWCanvas("Guillaume Gervais' C++ Game Engine", 1440, 900, false);
    Renderer *renderer = new GLRenderer(canvas);
    Timer *timer = new GLFWTimer(0.017);
    Input * input = new GLFWInput();
    Scene scene(renderer);

    // Setup game
    Game game(&scene, renderer, timer, input);
    game.init();

    // Setup scene graph
	Effect effect;

	Matrix4x4 identity = Matrix4x4::createIdentity();
	MeshNode node1("Node1", &identity);
    VertexBuffer &vb = node1.getVertexBuffer();
    Vertex v;
    v.x = 0.5;
    v.y = 0.5;
    v.z = 0;
    v.w = 1;
    v.r = 1.0;
    v.g = 0.0;
    v.b = 0.0;
    v.a = 1.0;
    vb.addVertex(v);
    
    v.x = 0.0;
    v.y = 0.0;
    v.r = 0.0;
    v.g = 1.0;
    vb.addVertex(v);
    
    v.x = 1.0;
    v.g = 0.0;
    v.b = 1.0;
    vb.addVertex(v);
    
    vb.addIndex(0);
    vb.addIndex(1);
    vb.addIndex(2);



    node1.setEffect(&effect);
	
	scene.addChild(&node1);

    
    // Setup shader
    Shader *vertexShader = renderer->createShader(VERTEX_SHADER, "hello-gl.v.glsl");
    Shader *fragmentShader = renderer->createShader(FRAGMENT_SHADER, "hello-gl.f.glsl");
    vertexShader->compile();
    fragmentShader->compile();

    Program *program = renderer->createProgram(vertexShader, fragmentShader);
    program->link();
    program->registerAttribute("position");
    program->registerAttribute("color");
    program->registerAttribute("normal");
    program->registerAttribute("texCoords");

    program->registerUniform("modelViewMatrix");
    program->registerUniform("projectionMatrix");

    effect.setProgram(program);
       
    game.mainLoop();
    game.dispose();
    
    renderer->deleteVertexBuffer(vb);

    delete program;
    delete fragmentShader;
    delete vertexShader;
    delete input;
    delete timer;
    delete canvas;
    delete renderer;
    

    std::cout << "Deleted all objects." << std::endl;
	std::string t;
	std::cin >> t;


    return EXIT_SUCCESS;
}

