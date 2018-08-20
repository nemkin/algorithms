/*
 * This source file contains utility functions which might be used in the bot program.
 *
 * Obviously other functions may also be implemented.
 */

#include <Util.h>
#include <math.h>

/****| FUNCTION DEFINITIONS |*************************************************/

boolean isNearZero(double value) {
	return (-EPSILON < value) && (value < EPSILON);
}

double signum(double value) {
	if (value < 0.0) {
		return -1.0;
	}
	if (0.0 < value) {
		return 1.0;
	}
	return 0.0;
}

double pow2(double value) {
	return value * value;
}

double min(double a, double b) {
	return (a < b) ? a : b;
}

double max(double a, double b) {
	return (a < b) ? b : a;
}

Vector createVector(double x, double y) {
	Vector result = {
		x,
		y };
	return result;
}

Vector unitVector(double angleRadian) {
	Vector result = {
		cos(angleRadian),
		sin(angleRadian) };
	return result;
}

Vector sum(Vector a, Vector b) {
	Vector result = {
		a.x + b.x,
		a.y + b.y };
	return result;
}

Vector scale(Vector vector, double factor) {
	Vector result = {
		factor * vector.x,
		factor * vector.y };
	return result;
}

Vector rotate(Vector vector, double angleRadian) {
	Vector result;
	double s = sin(angleRadian);
	double c = cos(angleRadian);

	result.x = c * vector.x - s * vector.y;
	result.y = s * vector.x + c * vector.y;

	return result;
}

double product(Vector a, Vector b) {
	return a.x * b.x + a.y * b.y;
}
