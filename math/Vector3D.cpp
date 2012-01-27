/* 
 * File:   Vector3D.cpp
 * Author: Guillaume
 * 
 * Created on January 23, 2012, 10:54 PM
 */

#include "Vector3D.hpp"

Vector3D::Vector3D()
{
    v[0] = 0;
    v[1] = 0;
    v[2] = 0;
}

Vector3D::Vector3D(float x, float y, float z)
{
    v[0] = x;
    v[1] = y;
    v[2] = z;
}

Vector3D::Vector3D(const Vector3D& orig) {
    v[0] = orig.v[0];
    v[1] = orig.v[1];
    v[2] = orig.v[2];
}

float Vector3D::dot(Vector3D &other) {
    return x()*other.x() + y()*other.y() + z()*other.z();
}

void Vector3D::normalize() {
    float l = length();
    if (l > 0) {
        v[0] = (v[0] / l);
        v[1] = (v[1] / l);
        v[2] = (v[2] / l);
    }
}

Vector3D Vector3D::normalized() {
    Vector3D vector(*this);
    vector.normalize();
    return vector;
}


Vector3D::~Vector3D() {
}

float Vector3D::x() const {
    return v[0];
}

float Vector3D::y() const {
    return v[1];
}

float Vector3D::z() const {
    return v[2];
}

void Vector3D::x(float x) {
    v[0] = x;
}

void Vector3D::y(float y) {
    v[1] = y;
}

void Vector3D::z(float z) {
    v[2] = z;
}

float *Vector3D::get() {
    return v;
}

float Vector3D::lengthSquared() {
    return v[0]*v[0] + v[1]*v[1] + v[2]*v[2];
}

float Vector3D::length() {
    return sqrt(lengthSquared());
}

Vector3D& Vector3D::operator=(const Vector3D &other) {
    if (this != &other) {
        x(other.x());
        y(other.y());
        z(other.z());
    }
    
    return *this;
}

Vector3D& Vector3D::operator+=(const Vector3D &other) {

    x(x() + other.x());
    y(y() + other.y());
    z(z() + other.z());
    
    return *this;
}

Vector3D& Vector3D::operator-=(const Vector3D &other) {
    
    x(x() - other.x());
    y(y() - other.y());
    z(z() - other.z());
    
    return *this;
    
}

// Cross product
Vector3D& Vector3D::operator*=(const Vector3D &other) {
    
    float xValue = x();
    float yValue = y();
    float zValue = z();
    
    x(yValue * other.z() - other.y() * zValue);
    y(zValue * other.x() - other.z() * xValue);
    z(xValue * other.y() - other.x() * yValue);
    
    return *this;
}

const Vector3D Vector3D::operator+(const Vector3D &other) const {
    Vector3D result = *this;
    result += other;
    return result;
}

const Vector3D Vector3D::operator-(const Vector3D &other) const {
    Vector3D result = *this;
    result -= other;
    return result;
}

const Vector3D Vector3D::operator*(const Vector3D &other) const {
    Vector3D result = *this;
    result *= other;
    return result;
}

std::ostream &operator<<(std::ostream &out, const Vector3D &vector) {
    out << "[" << vector.x() << ", " << vector.y() << ", " << vector.z() << "]";
    return out;
}