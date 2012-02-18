/* 
 * File:   Input.cpp
 * Author: Guillaume
 * 
 * Created on January 22, 2012, 1:50 AM
 */

#include "Input.hpp"
#include "KeyboardEvent.hpp"
#include "MouseMotionEvent.hpp"

Input::Input() {

    KeyState defaultKeyState;
    defaultKeyState.lastTimePressed = 0;
    defaultKeyState.isPressed = false;

    this->keyStates[W] = defaultKeyState;
    this->keyStates[A] = defaultKeyState;
    this->keyStates[S] = defaultKeyState;
    this->keyStates[D] = defaultKeyState;
    this->keyStates[ESCAPE] = defaultKeyState;
    this->keyStates[SPACEBAR] = defaultKeyState;

    this->mouseX = 0;
    this->mouseY = 0;

    this->viewportCenter = Vector3D(0, 0, 0);
    
    bool firstUpdate = true;
}

Input::~Input() {
}

void Input::update(double time) {
    for (std::map<Key, KeyState>::iterator it = this->keyStates.begin(); it != this->keyStates.end(); it++) {
        
        Key key = it->first;
        KeyState previousState = it->second;
        bool isPressedNow = isKeyPressed(key);

        bool previouslyPressed = previousState.isPressed;


        if (previouslyPressed != isPressedNow) {
            if (isPressedNow) {
                std::cout << "Key pressed! " << key << "." << std::endl;
                fireKeyPressedEvent(key);
            } else {
                std::cout << "Key released! " << key << "." << std::endl;
                fireKeyReleasedEvent(key);
            }
        } else if (isPressedNow) {
            if (time - previousState.lastTimePressed >= REPEAT_DELAY) {
                std::cout << "Repeat event (key pressed) ! " << key << "." << std::endl;
                this->keyStates[key].lastTimePressed = time;
                fireKeyPressedEvent(key);
            }
        }

        this->keyStates[key].isPressed = isPressedNow;
    }

    Vector3D mousePosition = getMousePosition();
    int posX = mousePosition.x();
    int posY = mousePosition.y();

    if (viewport) {
        viewportCenter.x(this->viewport->getWidth() / 2);
        viewportCenter.y(this->viewport->getHeight() / 2);
    }

    int centerX = viewportCenter.x();
    int centerY = viewportCenter.y();
    
    /*int diffX = (!this->firstUpdate ? posX - this->mouseX : 0);
    int diffY = (!this->firstUpdate ? posY - this->mouseY : 0);*/

    int diffX = (!this->firstUpdate ? posX - centerX : 0);
    int diffY = (!this->firstUpdate ? posY - centerY : 0);

    this->mouseX += diffX;
    this->mouseY += diffY;

    this->firstUpdate = false;

    if (diffX != 0 && diffY != 0) {
        std::cout << "Fire event" << std::endl;
        fireMouseMotionEvent(diffX, diffY);
    }
}

bool Input::isEscapePressed() const {
    bool isPressed = false;
    
    std::map<Key, KeyState>::const_iterator found = this->keyStates.find(ESCAPE);
    if (found != this->keyStates.end()) {
        isPressed = found->second.isPressed;
    }

    return isPressed;
}

void Input::addKeyboardListener(KeyboardListener *listener) {
    this->keyboardListeners.push_back(listener);
}

void Input::addMouseMotionListener(MouseMotionListener *listener) {
    this->mouseMotionListeners.push_back(listener);
}

void Input::fireKeyPressedEvent(Key key) {
    KeyboardEvent keyboardEvent(key);
    std::cout << "fireKeyPressedEvent " << key << std::endl;
    for (std::vector<KeyboardListener*>::iterator it = this->keyboardListeners.begin(); it != this->keyboardListeners.end(); it++) {
        (*it)->onKeyPressed(keyboardEvent);
    }
}

void Input::fireKeyReleasedEvent(Key key) {
    KeyboardEvent keyboardEvent(key);
    std::cout << "fireKeyReleasedEvent " << key << std::endl;    
    for (std::vector<KeyboardListener*>::iterator it = this->keyboardListeners.begin(); it != this->keyboardListeners.end(); it++) {
        (*it)->onKeyReleased(keyboardEvent);
    }
}

void Input::fireMouseMotionEvent(int diffX, int diffY) {
    MouseMotionEvent mouseMotionEvent(diffX, diffY);
    for (std::vector<MouseMotionListener*>::iterator it = this->mouseMotionListeners.begin(); it != this->mouseMotionListeners.end(); it++) {
        (*it)->onMouseMove(mouseMotionEvent);
    }
}

void Input::setViewport(Viewport *viewport) {
    this->viewport = viewport;
}