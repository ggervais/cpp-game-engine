/* 
 * File:   Input.hpp
 * Author: Guillaume
 *
 * Created on January 22, 2012, 1:50 AM
 */

#ifndef INPUT_HPP
#define	INPUT_HPP

#include <iostream>
#include <map>

enum Key {
    W,
    A,
    S,
    D,
    ESCAPE,
    SPACEBAR
};

class Input {
public:
    Input();
    virtual ~Input();
    virtual bool isEscapePressed() const;
    virtual void update(double time);
    virtual bool isKeyPressed(Key key) const = 0;
protected:
    std::map<Key, bool> keyState;
};

#endif	/* INPUT_HPP */

