/* 
 * File:   Game.cpp
 * Author: Guillaume
 * 
 * Created on January 21, 2012, 12:35 AM
 */

#include "Game.hpp"
#include <GL/glfw.h>

Game::Game(Renderer *renderer) :
        renderer(renderer)
{
}

Game::Game(const Game& orig) {
}

Game::~Game() {
}

void Game::init() {
    this->renderer->init();
}

void Game::mainLoop() {
    
    double quantumInSeconds = QUANTUM / 1000.0;
    double currentTime = glfwGetTime();
    double previousTime = currentTime;
    
    bool running = true;
    
    while (running) {
        
        currentTime = glfwGetTime();
        double timeDifference = currentTime - previousTime;
        
        if (timeDifference > quantumInSeconds) {
            this->renderer->render();
            previousTime = currentTime;
        } else {
            double sleepTime = quantumInSeconds - timeDifference;
            glfwSleep(sleepTime);
        }
        
        running = !glfwGetKey(GLFW_KEY_ESC) && glfwGetWindowParam(GLFW_OPENED);
    }
}
