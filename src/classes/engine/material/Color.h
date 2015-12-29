/*! \file Color.h
 *  \brief Basic color handling class
 *
 *  Created on: Dec 28, 2015\n
 *  Author: <mailto:bartag84@gmail.com>
 */

#ifndef SRC_CLASSES_ENGINE_MATERIAL_COLOR_H_
#define SRC_CLASSES_ENGINE_MATERIAL_COLOR_H_

namespace engine {

/**
 * Basic color handler class.
 */
class Color {
    public:
        /// @name Base colors
        //@{
        static const Color BLACK; /**< Black base color (0.0, 0.0, 0,0) */
        static const Color WHITE; /**< White base color (1.0, 1.0, 1,0) */
        static const Color RED; /**< Red base color (1.0, 0.0, 0,0) */
        static const Color GREEN; /**< Green base color (0.0, 1.0, 0,0) */
        static const Color BLUE; /**< Blue base color (0.0, 0.0, 1,0) */
        //@}

        /**
         * Enumerator for different standards
         */
        typedef enum Gamut_e {
            BT601 = 0, /**< Standard Definition */
            BT709, /**< High Definition */
            BT2020 /**< Ultra High Definition */
        } Gamut;

    private:
        double r, g, b, alpha;

    public:
        /**
         * Default constructor
         */
        Color();

        /**
         * Constructor
         * @param r Red component value
         * @param g Green component value
         * @param b Blue component value
         * @param alpha Alpha channel value
         */
        Color(double r, double g, double b, double alpha = 1.0);

        /**
         * Copy constructor
         * @param color Reference used for initialization
         */
        Color(const Color& color);

        /**
         * Virtual destructor
         */
        virtual ~Color();

        /// @name Operators
        //@{
        /** Color assignment operator */
        void operator=(const Color& color);

        /** Color addition operator */
        Color operator+(const Color& color);

        /** Color subtraction operator */
        Color operator-(const Color& color);

        /** Scaler operator */
        Color operator*(const double& scale);
        //@}

        /// @name Getters and setters
        //@{
        /**
         * Gets red component value
         * @return red component
         */
        double getR();

        /**
         * Gets green component value
         * @return green component
         */
        double getG();

        /**
         * Gets blue component value
         * @return blue component
         */
        double getB();

        /**
         * Sets the RGB components
         * @param r red component
         * @param g green component
         * @param b blue component
         */
        void set(double r, double g, double b);

        /**
         * Sets the RGB components and alpha
         * @param r red component
         * @param g green component
         * @param b blue component
         * @param alpha alpha
         */
        void set(double r, double g, double b, double alpha);

        /**
         * Gets the alpha value
         * @return alpha
         */
        double getAlpha();

        /**
         * Sets the alpha value
         * @param alpha alpha
         */
        void setAlpha(double alpha);
        //@}

        /// @name Utilities
        //@{
        /**
         * Calculates the luminance of the color
         * @return luminance
         */
        double getLuminance();
        //@}
};

} /* engine namespace */

#endif /* SRC_CLASSES_ENGINE_MATERIAL_COLOR_H_ */
