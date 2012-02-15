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
#include <vector>
#include "KeyboardListener.hpp"

class KeyboardEvent;
class KeyboardListener;

const double REPEAT_DELAY = 0.01;

struct KeyState {
    double lastTimePressed;
    bool isPressed;
};

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
    void addKeyboardListener(KeyboardListener *listener);
protected:
    std::map<Key, KeyState> keyStates;
private:
    std::vector<KeyboardListener*> keyboardListeners;
    void fireKeyPressedEvent(Key key);
    void fireKeyReleasedEvent(Key key);
};

#endif	/* INPUT_HPP */

