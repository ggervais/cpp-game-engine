/* 
 * File:   Vector3D.hpp
 * Author: Guillaume
 *
 * Created on January 23, 2012, 10:54 PM
 */

#ifndef VECTOR3D_HPP
#define	VECTOR3D_HPP

#include <iostream>
#include <math.h>
#include <string>

class Vector3D {
public:
    Vector3D();
    Vector3D(float x, float y, float z);
    Vector3D(const Vector3D& orig);
    virtual ~Vector3D();
    
    // Operator overloads
    Vector3D& operator=(const Vector3D &other);
    Vector3D& operator+=(const Vector3D &other);
    Vector3D& operator-=(const Vector3D &other);
    Vector3D& operator*=(const Vector3D &other);
    
    Vector3D operator+(const Vector3D &other) const;
    Vector3D operator-(const Vector3D &other) const;
    Vector3D operator*(const Vector3D &other) const;
    
    friend std::ostream &operator<<(std::ostream &out, const Vector3D &vector);
    
    float x() const;
    float y() const;
    float z() const;
    float w() const;
    
    void x(float x);
    void y(float y);
    void z(float z);
    void w(float w);
    
    float *get();
    float dot(Vector3D &other);
    
    float length();
    float lengthSquared();
    
    void normalize();
    Vector3D normalized();
private:
    float v[4];
};

#endif	/* VECTOR3D_HPP */

