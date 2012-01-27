/* 
 * File:   Matrix4x4.hpp
 * Author: Guillaume
 *
 * Created on January 26, 2012, 6:53 PM
 */

#ifndef MATRIX4X4_HPP
#define	MATRIX4X4_HPP

#include <iostream>

class Matrix4x4 {
public:
    Matrix4x4();
    Matrix4x4(const Matrix4x4& orig);
    virtual ~Matrix4x4();
    
    void makeIdentity();
    static Matrix4x4 createIdentity();
    
    Matrix4x4 inverse() throw(int);
    Matrix4x4 transpose();
    
    void set(int i, int j, float v);
    float get(int i, int j) const;
    
    Matrix4x4& operator*=(const Matrix4x4 &b);
    const Matrix4x4 operator*(const Matrix4x4 &b) const;
    friend std::ostream &operator<<(std::ostream &out, const Matrix4x4 &matrix);
    Matrix4x4& operator=(const Matrix4x4 &other);
private:
    float m[16];
};

#endif	/* MATRIX4X4_HPP */

