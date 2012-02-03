/* 
 * File:   GLFWTimer.hpp
 * Author: Guillaume
 *
 * Created on January 22, 2012, 1:06 AM
 */

#ifndef GLFWTIMER_HPP
#define	GLFWTIMER_HPP

#include "Timer.hpp"
#include <GL/glfw.h>

class GLFWTimer : public Timer {
public:
    GLFWTimer(double quantum);
    virtual ~GLFWTimer();
    double getTime() const;
    void sleep(double time);
private:

};

#endif	/* GLFWTIMER_HPP */

