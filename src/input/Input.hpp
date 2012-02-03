/* 
 * File:   Input.hpp
 * Author: Guillaume
 *
 * Created on January 22, 2012, 1:50 AM
 */

#ifndef INPUT_HPP
#define	INPUT_HPP

#include <iostream>

class Input {
public:
    Input();
    virtual ~Input();
    virtual bool isEscapePressed() const = 0;
private:

};

#endif	/* INPUT_HPP */

