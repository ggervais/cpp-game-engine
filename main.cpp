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

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

/*
 * 
 */
int main(int argc, char* argv[]) {

    GLFWCanvas canvas("Guillaume Gervais' C++ Game Engine", 1440, 900, false);
    GLRenderer renderer(&canvas);
    GLFWTimer timer(0.017);
    GLFWInput input;
   
    Game game(&renderer, &timer, &input);
    game.init();
    game.mainLoop();
    
    return EXIT_SUCCESS;
}

