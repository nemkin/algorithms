#ifndef UTIL_H
#define UTIL_H

/****| DEFINES |**************************************************************/

/*
 * Used to compare double values, this is the accepted difference to
 * consider the 'equal'
 */
#define EPSILON 	0.001

/* Literal for the boolean type representing true */
#define TRUE        1

/* Literal for the boolean type representing false */
#define FALSE       0


/****| TYPES |****************************************************************/

/* Boolean type */
typedef unsigned int boolean;


/* A 2 dimensional vector, used to represent position and offset */
typedef struct Vector {

	/* The x component */
	double x;

	/* The y component */
	double y;

} Vector;

/****| EXTERN FUNCTION DECLARATIONS |*****************************************/

/**
 * Checks if the value is near 0.
 *
 * @param value [in] the value
 *
 * @return TRUE if the value is near zero (EPSILON range), FALSE otherwise
 */
boolean isNearZero(double value);

/**
 * Signum function.
 *
 * @param value [in] the value
 *
 * @return the signum
 */
double signum(double value);

/**
 * Function: y = x*x.
 *
 * @param [in] value the value
 *
 * @return value*value
 */
double pow2(double value);

/*
 * Gets the smaller number of the two arguments.
 *
 * @param a [in] the first argument
 * @param b [in] the second argument
 *
 * @return the smaller number of the two arguments
 */
double min(double a, double b);

/*
 * Gets the bigger number of the two arguments.
 *
 * @param a [in] the first argument
 * @param b [in] the second argument
 *
 * @return the smaller number of the two arguments
 */
double max(double a, double b);

/*
 * Creates a vector.
 *
 * @param x [in] the x coordinate/magnitude
 * @param y [in] the y coordinate/magnitude
 *
 * @return the vector
 */
Vector createVector(double x, double y);

/*
 * Creates an unit length (1) vector with the specified direction.
 *
 * @param angleRadian [in] the direction in radians
 *
 * @return the unit vector
 */
Vector unitVector(double angleRadian);

/**
 * Adds the vectors together.
 *
 * @param a [in] the first vector
 * @param b [in] the second vector
 *
 * @return the sum of the two vectors
 */
Vector sum(Vector a, Vector b);

/**
 * Scales the vector (multiplication by a scalar).
 *
 * @param vector [in] the vector
 * @param factor [in] the scale factor
 *
 * @return the scaled vector
 */
Vector scale(Vector vector, double factor);

/**
 * Rotates the vector.
 *
 * @param vector [in] the vector
 * @param angleRadian [in] the rotation amount in radians
 *
 * @return the rotated vector
 */
Vector rotate(Vector vector, double angleRadian);

/**
 * Multiplies the vectors together (scalar product).
 *
 * @param a [in] the first vector
 * @param b [in] the second vector
 *
 * @return the scalar product of the two vectors
 */
double product(Vector a, Vector b);

#endif /* UTIL_H */
