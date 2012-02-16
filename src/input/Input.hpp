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
#include "MouseMotionListener.hpp"
#include "../math/Vector3D.hpp"

class KeyboardEvent;
class KeyboardListener;

class MouseMotionEvent;
class MouseMotionListener;

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
    void addMouseMotionListener(MouseMotionListener *listener);
protected:
    std::map<Key, KeyState> keyStates;
    
private:

    bool firstUpdate;
    int mouseX;
    int mouseY;


    std::vector<KeyboardListener*> keyboardListeners;
    std::vector<MouseMotionListener*> mouseMotionListeners;

    void fireKeyPressedEvent(Key key);
    void fireKeyReleasedEvent(Key key);
    void fireMouseMotionEvent(int diffX, int diffY);
    virtual Vector3D getMousePosition() const = 0;
};

#endif	/* INPUT_HPP */

