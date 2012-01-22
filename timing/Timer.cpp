/* 
 * File:   Timer.cpp
 * Author: Guillaume
 * 
 * Created on January 22, 2012, 12:54 AM
 */

#include "Timer.hpp"

Timer::Timer(double quantum) :
        quantum(quantum)
{
}

Timer::~Timer() {
}

double Timer::getQuantum() {
    return this->quantum;
}
