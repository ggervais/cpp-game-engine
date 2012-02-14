/* 
 * File:   Game.cpp
 * Author: Guillaume
 * 
 * Created on January 21, 2012, 12:35 AM
 */

#include "Game.hpp"
#include "../input/GLFWInput.hpp"

Game::Game(Scene *scene, Renderer *renderer, Timer *timer, Input *input) :
        scene(scene), renderer(renderer), timer(timer), input(input)
{
}

Game::Game(const Game& orig) :
        renderer(orig.renderer),
        timer(orig.timer),
        input(orig.input)
{
}

Game::~Game() {
}

void Game::init() {
    this->renderer->init();
    this->renderer->createVertexBuffer(this->vertexBuffer);
    
    Vertex v;
    v.x = 0.5;
    v.y = 0.5;
    v.z = 0;
    v.w = 1;
    v.r = 1.0;
    v.g = 0.0;
    v.b = 0.0;
    v.a = 1.0;
    this->vertexBuffer.addVertex(v);
    
    v.x = 0.0;
    v.y = 0.0;
    v.r = 0.0;
    v.g = 1.0;
    this->vertexBuffer.addVertex(v);
    
    v.x = 1.0;
    v.g = 0.0;
    v.b = 1.0;
    this->vertexBuffer.addVertex(v);
    
    this->vertexBuffer.addIndex(0);
    this->vertexBuffer.addIndex(1);
    this->vertexBuffer.addIndex(2);
    
    std::cout << "Game initialized." << std::endl;
}


void Game::dispose() {
    this->renderer->deleteVertexBuffer(this->vertexBuffer);
}

void Game::mainLoop() {
    
    double quantum = this->timer->getQuantum();
    double currentTime = this->timer->getTime();
    double previousTime = currentTime;
    
    bool running = true;
    
    while (running) {
        
        currentTime = this->timer->getTime();
        double timeDifference = currentTime - previousTime;
        
        if (timeDifference > quantum) {
            this->renderer->updateVertexBufferData(this->vertexBuffer);
            this->input->update(currentTime);
            this->scene->update(currentTime);
            this->scene->render();

            this->renderer->render(this->vertexBuffer);
            
            previousTime = currentTime;
        } else {
            double sleepTime = quantum - timeDifference;
            this->timer->sleep(sleepTime);
        }
        
        running = !input->isEscapePressed() && this->renderer->isWindowOpened();
    }
}
