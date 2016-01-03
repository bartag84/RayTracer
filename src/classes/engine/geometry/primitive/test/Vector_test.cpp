/*! \file Vector_test.cpp
 *  \brief Unit test for Vector class
 *
 *  Created on: Jan 3, 2016\n
 *  Author: <mailto:bartag84@gmail.com>
 */

#include <CppUTest/TestHarness.h>

#include "../Vector.h"

using namespace engine;

#define TOLERANCE     (0.0001)

TEST_GROUP(Vector)
{
        void equals(Vector& expected, Vector& actual) {
            DOUBLES_EQUAL(expected.getX(), actual.getX(), TOLERANCE);
            DOUBLES_EQUAL(expected.getY(), actual.getY(), TOLERANCE);
            DOUBLES_EQUAL(expected.getZ(), actual.getZ(), TOLERANCE);
        }
};

TEST(Vector, ConstructorTest)
{
    Vector undefinedVector;
    DOUBLES_EQUAL(0.0, undefinedVector.getX(), TOLERANCE);
    DOUBLES_EQUAL(0.0, undefinedVector.getY(), TOLERANCE);
    DOUBLES_EQUAL(0.0, undefinedVector.getZ(), TOLERANCE);

    Vector definedVector(0.1, 0.2, 0.3);
    DOUBLES_EQUAL(0.1, definedVector.getX(), TOLERANCE);
    DOUBLES_EQUAL(0.2, definedVector.getY(), TOLERANCE);
    DOUBLES_EQUAL(0.3, definedVector.getZ(), TOLERANCE);

    Vector copyVector(definedVector);
    DOUBLES_EQUAL(definedVector.getX(), copyVector.getX(), TOLERANCE);
    DOUBLES_EQUAL(definedVector.getY(), copyVector.getY(), TOLERANCE);
    DOUBLES_EQUAL(definedVector.getZ(), copyVector.getZ(), TOLERANCE);
}

TEST(Vector, OperatorTestAssignment)
{
    Vector a(0.1, 0.2, 0.3);
    Vector b;

    b = a;
    equals(a, b);
}

TEST(Vector, OperatorTestAddition)
{
    Vector a(0.1, 0.2, 0.3);
    Vector b(0.4, 0.5, 0.6);
    Vector expected(0.5, 0.7, 0.9);

    Vector result = a + b;
    equals(expected, result);
}

TEST(Vector, OperatorTestScaler)
{
    Vector a(0.1, 0.2, 0.3);
    Vector expected(0.2, 0.4, 0.6);

    Vector result = a * 2.0;
    equals(expected, result);
}

TEST(Vector, OperatorTestSubtraction)
{
    Vector a(0.1, 0.2, 0.3);
    Vector b(0.6, 0.5, 0.4);
    Vector expected(0.5, 0.3, 0.1);

    Vector result = b - a;
    equals(expected, result);

    expected = expected * -1.0;
    result = a - b;
    equals(expected, result);
}

TEST(Vector, OperatorTestDotProduct)
{
    double product = ((Vector)Vector::XBASEVECTOR) * Vector::YBASEVECTOR;
    DOUBLES_EQUAL(0, product, TOLERANCE);

    product = ((Vector)Vector::XBASEVECTOR) * Vector::ZBASEVECTOR;
    DOUBLES_EQUAL(0, product, TOLERANCE);

    product = ((Vector)Vector::ZBASEVECTOR) * Vector::YBASEVECTOR;
    DOUBLES_EQUAL(0, product, TOLERANCE);
}
