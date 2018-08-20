#include <CarDynamics.h>
#include <math.h>
#include <util.h>

/****| FUNCTION DEFINITIONS |*************************************************/

Car compute(Car car, Pedal pedal, Steering steering) {

	/* This is the next state that will be returned */
	Car nextCarState = car;

	/***| Handling gas and brake |************************/

	switch (pedal) {
	case Pedal_GAS:
		/* Increasing the kinetic energy of the car */
		nextCarState.speed =
				min(MAX_SPEED, sqrt(car.speed * car.speed + ENGINE_PERFORMANCE));
		break;
	case Pedal_BRAKE:
		/* Decreasing the kinetic energy of the car */
		nextCarState.speed =
				sqrt(max(0.0, car.speed * car.speed - BRAKE_PERFORMANCE));
		break;
	case Pedal_NONE:
	default:
		/* Nothing to do */
		break;
	}

	/***| Handling steering |*****************************/

	switch (steering) {
	case Steering_LEFT:
		/* Turning left (increasing steering angle), the new steering angle is PI/4.0 */
		nextCarState.steeringAngle = +TURN;
		break;
	case Steering_RIGHT:
		/* Turning right (decreasing steering angle), the new steering angle is -PI/4.0 */
		nextCarState.steeringAngle = -TURN;
		break;
	case Steering_NONE:
	default:
		/* No turning action, the steering angle 'slowly' returns to the center */
		nextCarState.steeringAngle =
				car.steeringAngle * ACTIVE_RETURN_FACTOR;
		break;
	}

	/***| Computing new position, direction and speed |***/

	if (isNearZero(nextCarState.steeringAngle))
	{
		/* The car running quasi-straight */
		nextCarState.position = sum(nextCarState.position,
				scale(unitVector(nextCarState.steeringAngle),
						nextCarState.speed));
	}
	else
	{
		/* The car is turning */

		/* The turn radius */
		double turnRadius =	CAR_LENGTH * sqrt(1.0 / 4.0 + 1.0 / pow2(tan(nextCarState.steeringAngle)));

		/* The sign of the turning, +: left -:right */
		double steeringAngleSign = signum(nextCarState.steeringAngle);

		/* The absolute amount of the turning of the car */
		double turnAngleAbs = nextCarState.speed / turnRadius;

		/* The signed turn angle that contains the left/right information */
		double turnAngle = steeringAngleSign * turnAngleAbs;

		/* The new direction of the car */
		nextCarState.direction += turnAngle;

		/* The new position of the car */
		nextCarState.position = sum(nextCarState.position,
				rotate(
						createVector(turnRadius * sin(turnAngleAbs),
								steeringAngleSign * turnRadius
										* (1.0 - cos(turnAngleAbs))),
						car.direction));

		/*
		 * Applying some 'crazy' physics for drifting that is not realistic at all,
		 * but it should make the race more interesting!
		 */
		{
			/* The 'drift offset' */
			Vector drift = scale(
					unitVector(
							nextCarState.direction
									+ steeringAngleSign
											* (-M_PI / 2.0 + turnAngle / 2.0)),
					turnRadius * turnAngleAbs * turnAngleAbs * DRIFTRATE);

			/* Drift is manifested as an offset to the movement */
			nextCarState.position = sum(
				nextCarState.position,
				drift);
		}
	}

	/* Applying speed loss to friction */
	nextCarState.speed = sqrt(
			max(0.0, ((nextCarState.speed * nextCarState.speed) - FRICTION_LOSS)));

	return nextCarState;
}
