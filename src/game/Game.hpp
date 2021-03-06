/* 
 * File:   Game.hpp
 * Author: Guillaume
 *
 * Created on January 21, 2012, 12:35 AM
 */

#ifndef GAME_HPP
#define	GAME_HPP

#include "../render/Renderer.hpp"
#include "../timing/Timer.hpp"
#include "../input/Input.hpp"
#include "../render/scenegraph/Scene.hpp"

class Game {
public:
    Game(Scene *scene, Renderer *renderer, Timer *timer, Input *input);
    Game(const Game& orig);
    virtual ~Game();
    void init();
    void dispose();
    void mainLoop();
private:
    static const int QUANTUM = 17;
    
    Scene *scene;
    Renderer *renderer;
    Timer *timer;
    Input *input;
    VertexBuffer vertexBuffer;
    
};

#endif	/* GAME_HPP */

