/* 
 * File:   Game.cpp
 * Author: Guillaume
 * 
 * Created on January 21, 2012, 12:35 AM
 */

#include "Game.hpp"

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
            this->renderer->render();
            previousTime = currentTime;
        } else {
            double sleepTime = quantum - timeDifference;
            this->timer->sleep(sleepTime);
        }
        
        running = !this->input->isEscapePressed() && this->renderer->isWindowOpened();
    }
}
