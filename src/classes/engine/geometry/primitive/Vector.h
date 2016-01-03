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
         * Scaler product
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
         * Gets the Radial distance in spherical coordinate system
         * @return Radial distance
         */
        double getRadialDistance();

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
         * @param r Radial distance
         * @param theta Polar angle (Theta)
         * @param phi Azimuth angle (Phi)
         */
        void setSphericalCoordinates(double r, double theta, double phi);
        //@}

        /// @name Utilities
        //@{
        /**
         * Creates the scaler product of two vectors
         * @param a Vector
         * @param b Vector
         * @return Scaler product of a and b (a.b)
         */
        static double scalerProduct(Vector a, Vector b);

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
