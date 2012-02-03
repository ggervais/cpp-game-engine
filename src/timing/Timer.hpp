/* 
 * File:   Timer.hpp
 * Author: Guillaume
 *
 * Created on January 22, 2012, 12:54 AM
 */

#ifndef TIMER_HPP
#define	TIMER_HPP

class Timer {
public:
    Timer(double quantum);
    virtual ~Timer();
    virtual double getTime() const = 0;
    virtual void sleep(double time) = 0;
    double getQuantum();
private:
    double quantum;
};

#endif	/* TIMER_HPP */

