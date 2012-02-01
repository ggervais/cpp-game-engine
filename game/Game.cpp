/* 
 * File:   Game.cpp
 * Author: Guillaume
 * 
 * Created on January 21, 2012, 12:35 AM
 */

#include "Game.hpp"

Game::Game(Renderer *renderer, Timer *timer, Input *input) :
        renderer(renderer), timer(timer), input(input), vertexBuffer(NULL)
{
}

Game::Game(const Game& orig) :
        renderer(orig.renderer),
        timer(orig.timer),
        input(orig.input),
        vertexBuffer(orig.vertexBuffer)
{
}

Game::~Game() {
    this->renderer->deleteVertexBuffer(this->vertexBuffer);
}

void Game::init() {
    this->renderer->init();
    this->vertexBuffer = this->renderer->createVertexBuffer();
    std::cout << "Game initialized. " << this->vertexBuffer << std::endl;
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
        
        running = !this->input->isEscapePressed() && this->renderer->isWindowOpened();
    }
}
