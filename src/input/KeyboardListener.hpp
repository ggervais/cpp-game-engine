/* 
 * File:   Input.hpp
 * Author: Guillaume
 *
 * Created on January 22, 2012, 1:50 AM
 */

#ifndef KEYBOARD_LISTENER_HPP
#define	KEYBOARD_LISTENER_HPP

#include "KeyboardEvent.hpp"

class KeyboardEvent;

class KeyboardListener {
public:
    virtual void onKeyPressed(KeyboardEvent &keyboardEvent) = 0;
    virtual void onKeyReleased(KeyboardEvent &keyboardEvent) = 0;
protected:
};

#endif	/* KEYBOARD_LISTENER_HPP */

