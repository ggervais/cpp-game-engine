/* 
 * File:   KeyboardEvent.hpp
 * Author: Guillaume
 *
 * Created on January 22, 2012, 1:50 AM
 */

#ifndef KEYBOARD_EVENT_HPP
#define	KEYBOARD_EVENT_HPP

#include "Input.hpp"

enum Key;
 
class KeyboardEvent {
public:
    KeyboardEvent(Key key);
    Key getKey();
    void setKey(Key key);
private:
    Key key;
};

#endif	/* KEYBOARD_EVENT_HPP */

