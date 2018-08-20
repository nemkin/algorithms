#ifndef CARDYNAMICS_H
#define CARDYNAMICS_H

/****| INCLUDES |*************************************************************/

#include <Util.h>
#include <math.h>

/****| MACRO DEFINITIONS |****************************************************/

/* The width of the car */
#define CAR_WIDTH				30.0

/* The length of the car */
#define CAR_LENGTH				60.0

/* The delta in the steering angle per tick possible when turning left/right */
#define TURN					(M_PI / 4.0)

/* The delta in kinetic energy per tick possible in case of gas */
#define ENGINE_PERFORMANCE		0.1

/* The delta in kinetic energy per tick possible in case of break */
#define BRAKE_PERFORMANCE		0.1

/* The rate which the steering angle return to the center */
#define ACTIVE_RETURN_FACTOR	0.9

/* The decrease in kinetic energy per tick if there is no gas/break */
#define FRICTION_LOSS			0.01

/* Constant used to compute drifting of the car when turning */
#define DRIFTRATE				3.0

/* The maximum speed the car can achieve */
#define MAX_SPEED				5.0

/****| TYPE DECLARATIONS |****************************************************/

/* Type for the possible pedal states */
typedef enum Pedal {

	/* The car will slowly decelerate */
	Pedal_NONE = 0U,

	/* The car will accelerate */
	Pedal_GAS = 1U,

	/* The car will decelerate */
	Pedal_BRAKE = 2U,

} Pedal;

/* Type for the possible steering actions*/
typedef enum Steering {

	/* The steering angle 'slowly' return to the center */
	Steering_NONE = 0U,

	/* The steering angle slightly increased */
	Steering_LEFT = 1U,

	/* The steering angle slightly decreased */
	Steering_RIGHT = 2U,

} Steering;

/* Describes the state of a car */
typedef struct Car {

	/* The position vector */
	Vector position;

	/* The direction in radians */
	double direction;

	/* The speed (movement per tick) */
	double speed;

	/* The angle of the front wheel in radians relative to the car's direction */
	double steeringAngle;

} Car;

/****| EXTERN FUNCTION DECLARATIONS |*****************************************/

/**
 * Computes the next state (for the next tick) of the car assuming that there
 * are no blocks or walls to be collided with.
 *
 * @param car [in] the state of the car
 * @param pedal [in] the state of the pedal, the pedal action taken
 * @param steering [in] the steering action taken
 *
 * @return the next state of the car
 */
extern Car compute(Car car, Pedal pedal, Steering steering);

#endif /* CARDYNAMICS_H */
