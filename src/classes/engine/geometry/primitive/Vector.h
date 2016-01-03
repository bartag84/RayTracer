/*! \file Vector.h
 *  \brief 3D vector handling class
 *
 *  Created on: Jan 3, 2016\n
 *  Author: <mailto:bartag84@gmail.com>
 */

#ifndef SRC_CLASSES_ENGINE_GEOMETRY_PRIMITIVE_VECTOR_H_
#define SRC_CLASSES_ENGINE_GEOMETRY_PRIMITIVE_VECTOR_H_

namespace engine {

/**
 * 3D Vector handling class
 */
class Vector {
    public:
        static const Vector NULLVECTOR;     //< Null vector
        static const Vector UNITYVECTOR;    //< Unity vector
        static const Vector XBASEVECTOR;    //< X base vector
        static const Vector YBASEVECTOR;    //< Y base vector
        static const Vector ZBASEVECTOR;    //< Z base vector

    private:
        double x, y, z;     //< Cartesian coordinates

    public:
        /**
         * Default constructor, it constructs a null vector
         */
        Vector();

        /**
         * Constructor for Cartesian coordinate system
         * @param x X coordinate
         * @param y Y coordinate
         * @param z Z coordinate
         */
        Vector(double x, double y, double z);

        /**
         * Copy constructor
         * @param vector Reference used for initialization
         */
        Vector(const Vector& vector);

        /**
         * Virtual destructor
         */
        virtual ~Vector();

        /// @name Operators
        //@{
        /**
         * Assignment
         */
        void operator=(const Vector& vector);

        /**
         * Vector addition
         */
        Vector operator+(const Vector& vector);

        /**
         * Vector subtraction
         */
        Vector operator-(const Vector& vector);

        /**
         * Vector scaling
         */
        Vector operator*(const double scale);

        /**
         * Dot product
         */
        double operator*(const Vector& vector);

        /**
         * Normalize the vector
         */
        void normalize();
        //@}

        /// @name Cartesian coordinate system getters and setters
        //@{
        /**
         * Gets the X coordiante
         * @return X coordinate
         */
        double getX();

        /**
         * Gets the Y coordinate
         * @return Y coordinate
         */
        double getY();

        /**
         * Gets the Z coordinate
         * @return Z coordinate
         */
        double getZ();

        /**
         * Sets the Cartesian coordinates
         * @param x X coordinate
         * @param y Y coordinate
         * @param z Z coordinate
         */
        void set(double x, double y, double z);
        //@}

        /// @name Spherical coordinate system getters and setters
        //@{
        /**
         * Gets the magnitude of the vector
         * @return Magnitude
         */
        double getMagnitude();

        /**
         * Gets the Polar angle (Theta) in spherical coordinate system
         * @return Polar angle
         */
        double getTheta();

        /**
         * Gets the Azimuth angle (Phi) in spherical coordinate system
         * @return Azimut angle
         */
        double getPhi();

        /**
         * Sets the coordiantes in spherical coordinate system
         * @param r Radial distance (Magnitude)
         * @param theta Polar angle (Theta)
         * @param phi Azimuth angle (Phi)
         */
        void setSphericalCoordinates(double r, double theta, double phi);
        //@}

        /// @name Utilities
        //@{
        /**
         * Gets the angle between the two vectors
         * @param a Vector
         * @param b Vector
         * @return Angle between a and b
         */
        static double getAngle(Vector a, Vector b);

        /**
         * Creates the cross product of two vectors
         * @param a Vector
         * @param b Vector
         * @return Cross product of a and b (a×b)
         */
        static Vector crossProduct(Vector a, Vector b);

        /**
         * Creates the normal vector of the plane defined by the two vectors
         * @param a Vector
         * @param b Vector
         * @return Normal vector of the plane
         */
        static Vector normalVector(Vector a, Vector b);
        //@}
};

} /* namespace engine */

#endif /* SRC_CLASSES_ENGINE_GEOMETRY_PRIMITIVE_VECTOR_H_ */
