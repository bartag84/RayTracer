/*! \file Color.cpp
 *  \brief Basic color handling class
 *
 *  Created on: Dec 28, 2015\n
 *  Author: <mailto:bartag84@gmail.com>
 */

#include "Color.h"

namespace engine {

const Color Color::BLACK(0.0, 0.0, 0.0);
const Color Color::WHITE(1.0, 1.0, 1.0);
const Color Color::RED(1.0, 0.0, 0.0);
const Color Color::GREEN(0.0, 1.0, 0.0);
const Color Color::BLUE(0.0, 0.0, 1.0);

Color::Color() {

    set(0.0, 0.0, 0.0, 1.0);
}

Color::Color(double r, double g, double b, double alpha) {

    set(r, g, b, alpha);
}

Color::Color(Color& color) {

    set(r, g, b, alpha);
}

Color::~Color() {
}

void Color::operator =(Color& color) {

    set(color.r, color.g, color.b, color.alpha);
}

Color Color::operator +(Color& color) {
    Color temp;

    temp.set(color.r + this->r, color.g + this->g, color.b + this->b,
            color.alpha + this->alpha);

    return temp;
}

Color Color::operator -(Color& color) {
    Color temp;

    temp.set(color.r - this->r, color.g - this->g, color.b - this->b,
            color.alpha - this->alpha);

    return temp;
}

Color Color::operator *(double scale) {
    Color temp;

    temp.set(scale * this->r, scale * this->g, scale * this->b);

    return temp;
}

double Color::getR() {

    return this->r;
}

double Color::getG() {

    return this->g;
}

double Color::getB() {

    return this->b;
}

double Color::getAlpha() {

    return this->alpha;
}

void Color::setAlpha(double alpha) {

    if (alpha < 0.0)
        this->alpha = 0.0;
    else if (alpha > 1.0)
        this->alpha = 1.0;
    else
        this->alpha = alpha;
}

void Color::set(double r, double g, double b) {

    if (r < 0.0)
        this->r = 0.0;
    else if (r > 1.0)
        this->r = 1.0;
    else
        this->r = r;

    if (g < 0.0)
        this->g = 0.0;
    else if (g > 1.0)
        this->g = 1.0;
    else
        this->g = g;

    if (b < 0.0)
        this->b = 0.0;
    else if (b > 1.0)
        this->b = 1.0;
    else
        this->b = b;
}

void Color::set(double r, double g, double b, double alpha) {

    set(r, g, b);
    setAlpha(alpha);
}

double Color::getLuminance() {

    return (this->r * 0.299 + this->g * 0.587 + this->b * 0.114);
}

}
