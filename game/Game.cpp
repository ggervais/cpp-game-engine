/* 
 * File:   Game.cpp
 * Author: Guillaume
 * 
 * Created on January 21, 2012, 12:35 AM
 */

#include "Game.hpp"
#include "../input/GLFWInput.hpp"

Game::Game(Renderer *renderer, Timer *timer, Input *input) :
        renderer(renderer), timer(timer), input(input)
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
            std::cout << "Will now update VBO data." << std::endl;
            this->renderer->updateVertexBufferData(this->vertexBuffer);
            this->renderer->render();
            
            previousTime = currentTime;
        } else {
            double sleepTime = quantum - timeDifference;
            this->timer->sleep(sleepTime);
        }
        
        running = !input->isEscapePressed() && this->renderer->isWindowOpened();
    }
}
