/* 
 * File:   Input.cpp
 * Author: Guillaume
 * 
 * Created on January 22, 2012, 1:50 AM
 */

#include "MouseMotionEvent.hpp"

MouseMotionEvent::MouseMotionEvent(int diffX, int diffY) : 
    diffX(diffX), diffY(diffY)
{
}

void MouseMotionEvent::setDiffXY(int diffX, int diffY) {
    this->diffX = diffX;
    this->diffY = diffY;
}

int MouseMotionEvent::getDiffX() const {
    return this->diffX;
}

int MouseMotionEvent::getDiffY() const {
    return this->diffY;
}