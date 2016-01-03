/*! \file Vector.cpp
 *  \brief
 *
 *  Created on: Jan 3, 2016\n
 *  Author: <mailto:bartag84@gmail.com>
 */

#include <math.h>

#include "Vector.h"

namespace engine {

const Vector Vector::NULLVECTOR = Vector();
const Vector Vector::UNITYVECTOR = Vector(1.0, 1.0, 1.0);
const Vector Vector::XBASEVECTOR = Vector(1.0, 0.0, 0.0);
const Vector Vector::YBASEVECTOR = Vector(0.0, 1.0, 0.0);
const Vector Vector::ZBASEVECTOR = Vector(0.0, 0.0, 1.0);

Vector::Vector() {

    this->x = 0.0;
    this->y = 0.0;
    this->z = 0.0;
}

Vector::Vector(double x, double y, double z) {

    this->x = x;
    this->y = y;
    this->z = z;
}

Vector::Vector(const Vector& vector) {

    this->x = vector.x;
    this->y = vector.y;
    this->z = vector.z;
}

Vector::~Vector() {
}

void Vector::operator =(const Vector& vector) {

    this->x = vector.x;
    this->y = vector.y;
    this->z = vector.z;
}

Vector Vector::operator +(const Vector& vector) {
    Vector temp;

    temp.set(this->x + vector.x, this->y + vector.y, this->z + vector.z);
    return temp;
}

Vector Vector::operator -(const Vector& vector) {
    Vector temp;

    temp.set(this->x - vector.x, this->y - vector.y, this->z - vector.z);
    return temp;
}

Vector Vector::operator *(const double scale) {
    Vector temp;

    temp.set(this->x * scale, this->y * scale, this->z * scale);
    return temp;
}

double Vector::operator *(const Vector& vector) {

    return (this->x * vector.x) + (this->y * vector.y) + (this->z * vector.z);
}

void Vector::normalize() {
    double r = getMagnitude();

    if (r != 0.0) {
        this->x /= r;
        this->y /= r;
        this->z /= r;

    } else {
        this->x = 0.0;
        this->y = 0.0;
        this->z = 0.0;
    }
}

double Vector::getX() {

    return x;
}

double Vector::getY() {

    return y;
}

double Vector::getZ() {

    return z;
}

void Vector::set(double x, double y, double z) {

    this->x = x;
    this->y = y;
    this->z = z;
}

double Vector::getMagnitude() {

    return sqrt((this->x * this->x) + (this->y * this->y) + (this->z * this->z));
}

double Vector::getTheta() {
    double r = getMagnitude();

    if (r == 0.0)
        return 0.0;
    else
        return acos(this->z / r);
}

double Vector::getPhi() {

    if ((this->x * this->y) == 0.0)
        return 0.0;
    else
        return atan(this->y / this->x);
}

void Vector::setSphericalCoordinates(double r, double theta, double phi) {

    this->x = r * sin(theta) * cos(phi);
    this->y = r * sin(theta) * sin(phi);
    this->x = r * cos(theta);
}

double Vector::getAngle(Vector a, Vector b) {
    double ma = a.getMagnitude();
    double mb = b.getMagnitude();

    if (ma * mb == 0.0)
        return 0.0;
    else
        return acos(((a.x * b.x) + (a.y * b.y) + (a.z * b.z)) / ma / mb);
}

Vector Vector::crossProduct(Vector a, Vector b) {
    Vector temp;

    temp.set((a.y * b.z) - (a.z * b.y),
            (b.x * a.z) - (a.x * b.z),
            (a.x * b.y) - (b.x * a.y));
    return temp;
}

Vector Vector::normalVector(Vector a, Vector b) {
    Vector temp = crossProduct(a, b);

    temp.normalize();
    return temp;
}

} /* namespace engine */
