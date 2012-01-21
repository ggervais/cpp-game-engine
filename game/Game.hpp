/* 
 * File:   Game.hpp
 * Author: Guillaume
 *
 * Created on January 21, 2012, 12:35 AM
 */

#ifndef GAME_HPP
#define	GAME_HPP

#include "../render/Renderer.hpp"

class Game {
public:
    Game(Renderer *renderer);
    //Game(Renderer &renderer, Input 8input);
    Game(const Game& orig);
    virtual ~Game();
    void init();
    void mainLoop();
private:
    static const int QUANTUM = 17;
    Renderer *renderer;
};

#endif	/* GAME_HPP */

