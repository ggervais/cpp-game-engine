/* 
 * File:   Matrix4x4.cpp
 * Author: Guillaume
 * 
 * Created on January 26, 2012, 6:53 PM
 */

#include "Matrix4x4.hpp"
#include "Vector3D.hpp"

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

Matrix4x4 Matrix4x4::createProjection(float fov, float aspectRatio, float near, float far) {
    Matrix4x4 result;
    
    float top = near * tan(fov / 2.0f);
    float bottom = -top;
    float right = top * aspectRatio;
    float left = -right;
    
    float tanOfAngle = tan(fov);
    
    result.set(0, 0, 2 * near / (right - left));
    result.set(1, 1, 2 * near / (top - bottom));
    
    result.set(0, 2, (right + left) / (right - left));
    result.set(1, 2, (top + bottom) / (top - bottom));
    result.set(2, 2, -(far + near) / (far - near));
    result.set(2, 3, -(2 * far * near) / (far - near));
    result.set(3, 2, -1);
    result.set(3, 3, 0);
    
    /*
    result.set(2, 2, (far + near) / (far - near));
    result.set(2, 3, (-2 * far * near) / (far - near));
    result.set(3, 2, 1);
    result.set(4, 4, 0);*/
    
    return result;
}

Matrix4x4 Matrix4x4::createView(Vector3D eye, Vector3D lookAt, Vector3D up) {
    
    Matrix4x4 result;
    
    Vector3D zAxis = (lookAt - eye).normalized(); // Forward
    Vector3D xAxis = (zAxis * up).normalized(); // Right
    Vector3D yAxis = xAxis * zAxis; // Up
    
    result.set(0, 0, xAxis.x());
    result.set(0, 1, xAxis.y());
    result.set(0, 2, xAxis.z());
    result.set(0, 3, 0);
    
    result.set(1, 0, yAxis.x());
    result.set(1, 1, yAxis.y());
    result.set(1, 2, yAxis.z());
    result.set(1, 3, 0);
    
    result.set(2, 0, -zAxis.x());
    result.set(2, 1, -zAxis.y());
    result.set(2, 2, -zAxis.z());
    result.set(2, 3, 0);
    
    Matrix4x4 translation;
    Vector3D minusEye(-eye.x(), -eye.y(), -eye.z());
    
    result.set(0, 3, eye.dot(xAxis));
    result.set(1, 3, eye.dot(yAxis));
    result.set(2, 3, eye.dot(zAxis));
    
    return result;
}

float Matrix4x4::get(int i, int j) const {
    int index = i * 4 + j;
    return m[index];
}

void Matrix4x4::set(int i, int j, float v) {
    int index = i * 4 + j;
    m[index] = v;
}

const Matrix4x4 Matrix4x4::createColumnMajor(Matrix4x4 &orig) {
    Matrix4x4 result;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int indexRowMajor = i * 4 + j;
            int indexColMajor = j * 4 + i;
            result.m[indexColMajor] = orig.m[indexRowMajor];
        }
    }
    return result;
}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4 &b) const {
    Matrix4x4 result = *this;
    result *= b;
    return result;
}

Matrix4x4 Matrix4x4::transpose() {
    Matrix4x4 result;
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result.set(i, j, get(j, i));
        }
    }
    
    return result;
}

optional<Matrix4x4> Matrix4x4::inverse() const {
    
    Matrix4x4 inverse;
    optional<Matrix4x4> result = inverse;
    
    float a11 = get(0, 0);
    float a12 = get(0, 1);
    float a13 = get(0, 2);
    float a14 = get(0, 3);
    float a21 = get(1, 0);
    float a22 = get(1, 1);
    float a23 = get(1, 2);
    float a24 = get(1, 3);
    float a31 = get(2, 0);
    float a32 = get(2, 1);
    float a33 = get(2, 2);
    float a34 = get(2, 3);
    float a41 = get(3, 0);
    float a42 = get(3, 1);
    float a43 = get(3, 2);
    float a44 = get(3, 3);
    
    float det = a11*a22*a33*a44 + a11*a23*a34*a42 + a11*a24*a32*a43
              + a12*a21*a34*a43 + a12*a23*a31*a44 + a12*a24*a33*a41
              + a13*a21*a32*a44 + a13*a22*a34*a41 + a13*a24*a31*a42
              + a14*a21*a33*a42 + a14*a22*a31*a43 + a14*a23*a32*a41
              - a11*a22*a34*a43 - a11*a23*a32*a44 - a11*a24*a33*a42
              - a12*a21*a33*a44 - a12*a23*a34*a41 - a12*a24*a31*a43
              - a13*a21*a34*a42 - a13*a22*a31*a44 - a13*a24*a32*a41
              - a14*a21*a32*a43 - a14*a22*a33*a41 - a14*a23*a31*a42;
    
    
    if (det == 0) {
        result.clear();
        return result; 
    }
    
    
    float b11 = a22*a33*a44 + a23*a34*a42 + a24*a32*a43 - a22*a34*a43 - a23*a32*a44 - a24*a33*a42;
    float b12 = a12*a34*a43 + a13*a32*a44 + a14*a33*a42 - a12*a33*a44 - a13*a34*a42 - a14*a32*a43;
    float b13 = a12*a23*a44 + a13*a24*a42 + a14*a22*a43 - a12*a24*a43 - a13*a22*a44 - a14*a23*a42;
    float b14 = a12*a24*a33 + a13*a22*a34 + a14*a23*a32 - a12*a23*a34 - a13*a24*a32 - a14*a22*a33;

    float b21 = a21*a34*a43 + a23*a31*a44 + a24*a33*a41 - a21*a33*a44 - a23*a34*a41 - a24*a31*a43;
    float b22 = a11*a33*a44 + a13*a34*a41 + a14*a31*a43 - a11*a34*a43 - a13*a31*a44 - a14*a33*a41;
    float b23 = a11*a24*a43 + a13*a21*a44 + a14*a23*a41 - a11*a23*a44 - a13*a24*a41 - a14*a21*a43;
    float b24 = a11*a23*a34 + a13*a24*a31 + a14*a21*a33 - a11*a24*a33 - a13*a21*a34 - a14*a23*a31;

    float b31 = a21*a32*a44 + a22*a34*a41 + a24*a31*a42 - a21*a34*a42 - a22*a31*a44 - a24*a32*a41;
    float b32 = a11*a34*a42 + a12*a31*a44 + a14*a32*a41 - a11*a32*a44 - a12*a34*a41 - a14*a31*a42;
    float b33 = a11*a22*a44 + a12*a24*a41 + a14*a21*a42 - a11*a24*a42 - a12*a21*a44 - a14*a22*a41;
    float b34 = a11*a24*a32 + a12*a21*a34 + a14*a22*a31 - a11*a22*a34 - a12*a24*a31 - a14*a21*a32;

    float b41 = a21*a33*a42 + a22*a31*a43 + a23*a32*a41 - a21*a32*a43 - a22*a33*a41 - a23*a31*a42;
    float b42 = a11*a32*a43 + a12*a33*a41 + a13*a31*a42 - a11*a33*a42 - a12*a31*a43 - a13*a32*a41;
    float b43 = a11*a23*a42 + a12*a21*a43 + a13*a22*a41 - a11*a22*a43 - a12*a23*a41 - a13*a21*a42;
    float b44 = a11*a22*a33 + a12*a23*a31 + a13*a21*a32 - a11*a23*a32 - a12*a21*a33 - a13*a22*a31;
    
    b11 *= (1 / det);
    b12 *= (1 / det);
    b13 *= (1 / det);
    b14 *= (1 / det);
    b21 *= (1 / det);
    b22 *= (1 / det);
    b23 *= (1 / det);
    b24 *= (1 / det);
    b31 *= (1 / det);
    b32 *= (1 / det);
    b33 *= (1 / det);
    b34 *= (1 / det);
    b41 *= (1 / det);
    b42 *= (1 / det);
    b43 *= (1 / det);
    b44 *= (1 / det);
    
    result->set(0, 0, b11);
    result->set(0, 1, b12);
    result->set(0, 2, b13);
    result->set(0, 3, b14);

    result->set(1, 0, b21);
    result->set(1, 1, b22);
    result->set(1, 2, b23);
    result->set(1, 3, b24);

    result->set(2, 0, b31);
    result->set(2, 1, b32);
    result->set(2, 2, b33);
    result->set(2, 3, b34);

    result->set(3, 0, b41);
    result->set(3, 1, b42);
    result->set(3, 2, b43);
    result->set(3, 3, b44);
    
    
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

const float *Matrix4x4::get() {
    return m;
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

Vector3D Matrix4x4::getPosition() const {
	Vector3D result;

	result.x(get(0, 2));
	result.y(get(1, 2));
	result.z(get(2, 2));

	return result;
}

void Matrix4x4::setPosition(Vector3D position) {
    
    set(0, 2, position.x());
    set(1, 2, position.y());
    set(2, 2, position.z());
}
