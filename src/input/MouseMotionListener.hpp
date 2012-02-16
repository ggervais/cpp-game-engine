/* 
 * File:   Input.hpp
 * Author: Guillaume
 *
 * Created on January 22, 2012, 1:50 AM
 */

#ifndef MOUSE_MOTION_LISTENER_HPP
#define	MOUSE_MOTION_LISTENER_HPP

#include "MouseMotionEvent.hpp"

class MouseMotionEvent;

class MouseMotionListener {
public:
    virtual void onMouseMove(MouseMotionEvent &mouseMotionEvent) = 0;
protected:
};

#endif	/* MOUSE_MOTION_LISTENER_HPP */

