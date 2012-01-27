/* 
 * File:   Matrix4x4.cpp
 * Author: Guillaume
 * 
 * Created on January 26, 2012, 6:53 PM
 */

#include "Matrix4x4.hpp"

Matrix4x4::Matrix4x4() {
    makeIdentity();
}

Matrix4x4::Matrix4x4(const Matrix4x4& orig) {
    for (int i = 0; i < 16; i++) {
        m[i] = orig.m[i];
    }
}

Matrix4x4& Matrix4x4::operator=(const Matrix4x4 &other) {
    if (this != &other) {
        for (int i = 0; i < 16; i++) {
            this->m[i] = other.m[i];
        }
    }
    
    return *this;
}

Matrix4x4::~Matrix4x4() {
}

void Matrix4x4::makeIdentity() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int index = i * 4 + j;
            if (i == j) {
                m[index] = 1;
            } else {
                m[index] = 0;
            }
        }
    }
}

Matrix4x4 Matrix4x4::createIdentity() {
    Matrix4x4 matrix;
    return matrix;
}

float Matrix4x4::get(int i, int j) const {
    int index = i * 4 + j;
    return m[index];
}

void Matrix4x4::set(int i, int j, float v) {
    int index = i * 4 + j;
    m[index] = v;
}

const Matrix4x4 Matrix4x4::operator*(const Matrix4x4 &b) const {
    Matrix4x4 result = *this;
    result *= b;
    return result;
}

Matrix4x4& Matrix4x4::operator*=(const Matrix4x4 &b) {
    Matrix4x4 temp;

    // M00
    temp.set(0, 0, get(0, 0) * b.get(0, 0) +
                   get(0, 1) * b.get(1, 0) +
		   get(0, 2) * b.get(2, 0) +
		   get(0, 3) * b.get(3, 0));
    
    // M01
    temp.set(0, 1, get(0, 0) * b.get(0, 1) +
                   get(0, 1) * b.get(1, 1) +
		   get(0, 2) * b.get(2, 1) +
		   get(0, 3) * b.get(3, 1));
    
    // M03
    temp.set(0, 2, get(0, 0) * b.get(0, 2) +
                   get(0, 1) * b.get(1, 2) +
		   get(0, 2) * b.get(2, 2) +
		   get(0, 3) * b.get(3, 2));
    
    // M03
    temp.set(0, 3, get(0, 0) * b.get(0, 3) +
                   get(0, 1) * b.get(1, 3) +
		   get(0, 2) * b.get(2, 3) +
		   get(0, 3) * b.get(3, 3));

    // M10
    temp.set(1, 0, get(1, 0) * b.get(0, 0) +
                   get(1, 1) * b.get(1, 0) +
                   get(1, 2) * b.get(2, 0) +
                   get(1, 3) * b.get(3, 0));
		
    // M11
    temp.set(1, 1, get(1, 0) * b.get(0, 1) +
                   get(1, 1) * b.get(1, 1) +
                   get(1, 2) * b.get(2, 1) +
                   get(1, 3) * b.get(3, 1));
    // M12
    temp.set(1, 2, get(1, 0) * b.get(0, 2) +
                   get(1, 1) * b.get(1, 2) +
                   get(1, 2) * b.get(2, 2) +
                   get(1, 3) * b.get(3, 2));
    // M13
    temp.set(1, 3, get(1, 0) * b.get(0, 3) +
                   get(1, 1) * b.get(1, 3) +
                   get(1, 2) * b.get(2, 3) +
                   get(1, 3) * b.get(3, 3));
    

    // M20
    temp.set(2, 0, get(2, 0) * b.get(0, 0) +
                   get(2, 1) * b.get(1, 0) +
                   get(2, 2) * b.get(2, 0) +
                   get(2, 3) * b.get(3, 0));
    // M21
    temp.set(2, 1, get(2, 0) * b.get(0, 1) +
                   get(2, 1) * b.get(1, 1) +
                   get(2, 2) * b.get(2, 1) +
                   get(2, 3) * b.get(3, 1));
    // M22
    temp.set(2, 2, get(2, 0) * b.get(0, 2) +
                   get(2, 1) * b.get(1, 2) +
                   get(2, 2) * b.get(2, 2) +
                   get(2, 3) * b.get(3, 2));
    // M23
    temp.set(2, 3, get(2, 0) * b.get(0, 3) +
                   get(2, 1) * b.get(1, 3) +
                   get(2, 2) * b.get(2, 3) +
                   get(2, 3) * b.get(3, 3));
     
                
    // M30
    temp.set(3, 0, get(3, 0) * b.get(0, 0) +
                   get(3, 1) * b.get(1, 0) +
                   get(3, 2) * b.get(2, 0) +
                   get(3, 3) * b.get(3, 0));
    // M31
    temp.set(3, 1, get(3, 0) * b.get(0, 1) +
                   get(3, 1) * b.get(1, 1) +
                   get(3, 2) * b.get(2, 1) +
                   get(3, 3) * b.get(3, 1));
    // M32
    temp.set(3, 2, get(3, 0) * b.get(0, 2) +
                   get(3, 1) * b.get(1, 2) +
                   get(3, 2) * b.get(2, 2) +
                   get(3, 3) * b.get(3, 2));
    // M33
    temp.set(3, 3, get(3, 0) * b.get(0, 3) +
                   get(3, 1) * b.get(1, 3) +
                   get(3, 2) * b.get(2, 3) +
                   get(3, 3) * b.get(3, 3));
    
    for (int i = 0; i < 16; i++) {
        m[i] = temp.m[i];
    }
    
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Matrix4x4 &matrix) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int index = i * 4 + j;
            out << matrix.m[index];
            if (j < 3) {
                out << ", ";
            } else {
                out << std::endl;
            }
        }
    }
    return out;
}

