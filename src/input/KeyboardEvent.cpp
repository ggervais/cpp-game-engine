/* 
 * File:   Input.cpp
 * Author: Guillaume
 * 
 * Created on January 22, 2012, 1:50 AM
 */

#include "KeyboardEvent.hpp"

KeyboardEvent::KeyboardEvent(Key key) : 
    key(key)
{
}

Key KeyboardEvent::getKey() {
    return this->key;
}

void KeyboardEvent::setKey(Key key) {
    this->key = key;
}