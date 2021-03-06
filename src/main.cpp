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
#include "render/scenegraph/SphereNode.hpp"
#include "render/scenegraph/CameraNode.hpp"
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

    input->setViewport(&(canvas->getViewport()));

    //Matrix4x4 viewMatrix = Matrix4x4::createView(Vector3D(0, 0, 5), Vector3D(0, 0, -1000), Vector3D(0, 1, 0));
    Matrix4x4 viewMatrix = Matrix4x4::createIdentity();
    viewMatrix.setPosition(Vector3D(0, 0, 0));
    optional<Matrix4x4> viewWorldMatrix = viewMatrix.inverse();
    Matrix4x4 cameraTransformationMatrix = Matrix4x4::createIdentity();
    if (viewWorldMatrix.valid() ) {
        cameraTransformationMatrix = *viewWorldMatrix;
    }


    Scene scene(renderer);
    CameraNode *camera = new CameraNode("Camera", &(canvas->getViewport()), 0.785398163, 0.0001, 1000, &cameraTransformationMatrix);
    scene.setCamera(camera);


    // Setup game
    Game game(&scene, renderer, timer, input);
    game.init();

    // Setup scene graph
	Effect effect;

    
    Matrix4x4 world0 = Matrix4x4::createIdentity();
    world0.setPosition(Vector3D(0, 0, 0));

	Matrix4x4 world1 = Matrix4x4::createIdentity();
    world1.setPosition(Vector3D(0, 0, -5));

    BaseSceneNode node0("Node0", &world0);

	MeshNode node1("Node1", &world1);
    VertexBuffer &vb1 = node1.getVertexBuffer();
    Vertex v;
    v.x = 0;
    v.y = 0.5;
    v.z = 0;
    v.w = 1;
    v.r = 1.0;
    v.g = 0.0;
    v.b = 0.0;
    v.a = 1.0;
    vb1.addVertex(v);
    
    v.x = -0.5;
    v.y = 0.0;
    vb1.addVertex(v);
    
    v.x = 0.5;
    vb1.addVertex(v);
    
    vb1.addIndex(0);
    vb1.addIndex(1);
    vb1.addIndex(2);

    
    Matrix4x4 world2 = Matrix4x4::createIdentity();
    world2.setPosition(Vector3D(5, 0, 0));

    MeshNode node2("Node2", &world2);
    VertexBuffer &vb2 = node2.getVertexBuffer();

    v.x = 0;
    v.y = 0.5;
    v.z = 0;
    v.w = 1;
    v.r = 0.0;
    v.g = 1.0;
    v.b = 0.0;
    v.a = 1.0;
    vb2.addVertex(v);
    
    v.y = 0.0;
    v.z = -0.5;
    vb2.addVertex(v);
    
    v.z = 0.5;
    vb2.addVertex(v);
    
    vb2.addIndex(0);
    vb2.addIndex(1);
    vb2.addIndex(2);


    Matrix4x4 world3 = Matrix4x4::createIdentity();
    world3.setPosition(Vector3D(0, 0, 5));

    MeshNode node3("Node3", &world3);
    VertexBuffer &vb3 = node3.getVertexBuffer();

    v.x = 0;
    v.y = 0.5;
    v.z = 0;
    v.w = 1;
    v.r = 0.0;
    v.g = 0.0;
    v.b = 1.0;
    v.a = 1.0;
    vb3.addVertex(v);
    
    v.x = -0.5;
    v.y = 0.0;
    vb3.addVertex(v);
    
    v.x = 0.5;
    vb3.addVertex(v);
    
    vb3.addIndex(0);
    vb3.addIndex(1);
    vb3.addIndex(2);
    

    Matrix4x4 world4 = Matrix4x4::createIdentity();
    world4.setPosition(Vector3D(0, 0, 0));
    world4.setScale(Vector3D(10, 10, 10));

    MeshNode node4("Node2", &world4);
    VertexBuffer &vb4 = node4.getVertexBuffer();

    v.x = -0.5;
    v.y = 0;
    v.z = 0;
    v.w = 1;
    v.r = 1.0;
    v.g = 0.0;
    v.b = 1.0;
    v.a = 1.0;
    vb4.addVertex(v);
    
    v.x = 0.5;
    v.z = -0.5;
    vb4.addVertex(v);
    
    v.z = 0.5;
    vb4.addVertex(v);
    
    vb4.addIndex(0);
    vb4.addIndex(1);
    vb4.addIndex(2);

    Matrix4x4 sphereWorld = Matrix4x4::createIdentity();
    SphereNode sphere("Sphere", &sphereWorld);

    node0.addChild(&node1);
	node0.addChild(&node2);
	node0.addChild(&node3);
    node0.addChild(&node4);
    
    scene.addChild(&sphere);
    scene.addChild(&node0);

    node0.setEffect(&effect);

    input->addKeyboardListener(camera);
    input->addMouseMotionListener(camera);
    
    // Setup shader
    Shader *baseVertexShader = renderer->createShader(VERTEX_SHADER, "hello-gl.v.glsl");
    Shader *baseGeometryShader = renderer->createShader(GEOMETRY_SHADER, "pass-through.g.glsl");
    Shader *baseFragmentShader = renderer->createShader(FRAGMENT_SHADER, "hello-gl.f.glsl");

    bool vertexCompiled = baseVertexShader->compile();
    bool geometryCompiled = baseGeometryShader->compile();
    bool fragmentCompiled = baseFragmentShader->compile();

    if (vertexCompiled && geometryCompiled && fragmentCompiled) {

        Program *baseProgram = renderer->createProgram(baseVertexShader, baseFragmentShader);
        bool programLinked = baseProgram->link();
    
        if (programLinked) {
            baseProgram->registerAttribute("position");
            baseProgram->registerAttribute("color");
            baseProgram->registerAttribute("normal");
            baseProgram->registerAttribute("texCoords");

            baseProgram->registerUniform("worldMatrix");
            baseProgram->registerUniform("viewMatrix");
            baseProgram->registerUniform("projectionMatrix");
            baseProgram->registerUniform("useTexture");
            baseProgram->registerUniform("useLighting");

            effect.setProgram(baseProgram);
       

            Effect imposterEffect;
            Shader *imposterVertexShader = renderer->createShader(VERTEX_SHADER, "imposter.v.glsl");
            Shader *imposterGeometryShader = renderer->createShader(GEOMETRY_SHADER, "imposter.g.glsl");
            Shader *imposterFragmentShader = renderer->createShader(FRAGMENT_SHADER, "imposter.f.glsl");
            
            vertexCompiled = imposterVertexShader->compile();
            geometryCompiled = imposterGeometryShader->compile();
            fragmentCompiled = imposterFragmentShader->compile();

            if (vertexCompiled && geometryCompiled && fragmentCompiled) {
                Program *imposterProgram = renderer->createProgram(imposterVertexShader, imposterGeometryShader, imposterFragmentShader);    
            
                programLinked = imposterProgram->link();
                if (programLinked) {
                    imposterProgram->registerAttribute("position");
                    imposterProgram->registerAttribute("color");
                    imposterProgram->registerAttribute("normal");
                    imposterProgram->registerAttribute("texCoords");
                    imposterProgram->registerUniform("worldMatrix");
                    imposterProgram->registerUniform("viewMatrix");
                    imposterProgram->registerUniform("projectionMatrix");

                    imposterEffect.setProgram(imposterProgram);
                    sphere.setEffect(&imposterEffect);

                    
                    game.mainLoop();
                }

                delete imposterProgram;
            }
            
            delete imposterFragmentShader;
            delete imposterGeometryShader;
            delete imposterVertexShader;

        }

        delete baseProgram;
    }

    delete baseGeometryShader;
    delete baseFragmentShader;
    delete baseVertexShader;

    game.dispose();
    
    renderer->deleteVertexBuffer(vb1);
    renderer->deleteVertexBuffer(vb2);
    renderer->deleteVertexBuffer(vb3);
    renderer->deleteVertexBuffer(vb4);

    delete camera;
    delete input;
    delete timer;
    delete canvas;
    delete renderer;
    

    std::cout << "Deleted all objects." << std::endl;
	std::string t;
	std::cin >> t;


    return EXIT_SUCCESS;
}

