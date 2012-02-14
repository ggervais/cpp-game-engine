/* 
 * File:   Input.cpp
 * Author: Guillaume
 * 
 * Created on January 22, 2012, 1:50 AM
 */

#include "Input.hpp"

Input::Input() {
    this->keyState[W] = false;
    this->keyState[A] = false;
    this->keyState[S] = false;
    this->keyState[D] = false;
    this->keyState[ESCAPE] = false;
    this->keyState[SPACEBAR] = false;
}

Input::~Input() {
}

void Input::update(double time) {
    for (std::map<Key, bool>::iterator it = this->keyState.begin(); it != this->keyState.end(); it++) {
        
        Key key = it->first;
        bool previouslyPressed = it->second;
        bool isPressedNow = isKeyPressed(key);

        if (previouslyPressed != isPressedNow) {
            if (isPressedNow) {
                std::cout << "Key pressed! " << key << "." << std::endl;
            } else {
                std::cout << "Key released! " << key << "." << std::endl;
            }
        }

        this->keyState[key] = isPressedNow;
    }
}

bool Input::isEscapePressed() const {
    bool isPressed = false;
    
    std::map<Key, bool>::const_iterator found = this->keyState.find(ESCAPE);
    if (found != this->keyState.end()) {
        isPressed = found->second;
    }

    return isPressed;
}