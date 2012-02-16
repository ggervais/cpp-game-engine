/* 
 * File:   KeyboardEvent.hpp
 * Author: Guillaume
 *
 * Created on January 22, 2012, 1:50 AM
 */

#ifndef MOUSE_MOTION_EVENT_HPP
#define	MOUSE_MOTION_EVENT_HPP

#include "Input.hpp"
 
class MouseMotionEvent {
public:
    MouseMotionEvent(int diffX, int diffY);
    void setDiffXY(int diffX, int diffY);
    int getDiffX() const;
    int getDiffY() const;
private:
    int diffX; // In pixels, so int.
    int diffY; // In pixels, so int.
};

#endif	/* MOUSE_MOTION_EVENT_HPP */

