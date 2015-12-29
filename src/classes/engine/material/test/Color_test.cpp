/*! \file Color_test.cpp
 *  \brief Unit test for Color class
 *
 *  Created on: Dec 29, 2015\n
 *  Author: <mailto:bartag84@gmail.com>
 */

#include <CppUTest/TestHarness.h>

#include "../Color.h"

using namespace engine;

#define TOLERANCE     (0.0001)

TEST_GROUP(Color)
{
        void equals(Color& expected, Color& actual) {
            DOUBLES_EQUAL(expected.getR(), actual.getR(), TOLERANCE);
            DOUBLES_EQUAL(expected.getG(), actual.getG(), TOLERANCE);
            DOUBLES_EQUAL(expected.getB(), actual.getB(), TOLERANCE);
            DOUBLES_EQUAL(expected.getAlpha(), actual.getAlpha(), TOLERANCE);
        }
};

TEST(Color, ConstructorTest)
{
    Color undefinedColor;
    DOUBLES_EQUAL(0.0, undefinedColor.getR(), TOLERANCE);
    DOUBLES_EQUAL(0.0, undefinedColor.getG(), TOLERANCE);
    DOUBLES_EQUAL(0.0, undefinedColor.getB(), TOLERANCE);
    DOUBLES_EQUAL(0.0, undefinedColor.getAlpha(), TOLERANCE);

    Color definedColor(0.1, 0.2, 0.3);
    DOUBLES_EQUAL(0.1, definedColor.getR(), TOLERANCE);
    DOUBLES_EQUAL(0.2, definedColor.getG(), TOLERANCE);
    DOUBLES_EQUAL(0.3, definedColor.getB(), TOLERANCE);
    DOUBLES_EQUAL(1.0, definedColor.getAlpha(), TOLERANCE)

    Color copyColor(definedColor);
    DOUBLES_EQUAL(definedColor.getR(), copyColor.getR(), TOLERANCE);
    DOUBLES_EQUAL(definedColor.getG(), copyColor.getG(), TOLERANCE);
    DOUBLES_EQUAL(definedColor.getB(), copyColor.getB(), TOLERANCE);
    DOUBLES_EQUAL(definedColor.getAlpha(), copyColor.getAlpha(), TOLERANCE);
}

TEST(Color, OperatorTestAssingment)
{
    Color a(0.1, 0.2, 0.3);

    Color result = a;
    equals(result, a);
}

TEST(Color, OperatorTestAddition)
{
    Color a(0.1, 0.2, 0.3);
    Color b(0.4, 0.5, 0.6);
    Color expected(0.5, 0.7, 0.9);

    Color result = a + b;
    equals(expected, result);
}

TEST(Color, OperatorTestAdditionWithLimiting)
{
    Color a(0.4, 0.2, 0.3);
    Color b(0.8, 0.8, 0.8);
    Color expected(1.0, 1.0, 1.0);

    Color result = a + b;
    equals(expected, result);
}

TEST(Color, OperatorTestSubtraction)
{
    Color a(0.1, 0.2, 0.3);
    Color b(0.4, 0.6, 0.8);
    Color expected(0.3, 0.4, 0.5);

    Color result = b - a;
    equals(expected, result);
}

TEST(Color, OperatorTestScaler)
{
    Color a(0.1, 0.2, 0.3);
    double scale = 2.0;
    Color expected(0.2, 0.4, 0.6);

    Color result = a * scale;
    equals(expected, result);
}

TEST(Color, TestLuminance)
{
    Color black = Color::BLACK;
    DOUBLES_EQUAL(0.0, black.getLuminance(), TOLERANCE);

    Color white = Color::WHITE;
    DOUBLES_EQUAL(1.0, white.getLuminance(), TOLERANCE);
}
