/* 
 * File:   Input.cpp
 * Author: Guillaume
 * 
 * Created on January 22, 2012, 1:50 AM
 */

#include "Input.hpp"
#include "KeyboardEvent.hpp"

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