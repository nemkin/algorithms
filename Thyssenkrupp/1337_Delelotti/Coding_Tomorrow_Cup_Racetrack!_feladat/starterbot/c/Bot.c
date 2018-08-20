/*
 * This source file is a skeleton for a bot implementation. In each tick the
 * getAction() function is triggered by the simulator with the car's actual
 * position and direction. The function must return an action for the next tick.
 */

#include <Bot.h>
#include <CarDynamics.h>
#include <Util.h>

/****| VARIABLE DECLARATIONS |************************************************/

/* The (square) block size length */
double block_size;

/* The number of columns of the race track (x dimension) */
int racetrack_columns;

/* The number of rows of the race track (y dimension) */
int racetrack_rows;

/*
 * The blocks of the race track. *
 * 0    - empty block, the car can use it
 * -1   - wall block, the car shall avoid these
 * 1..  - checkpoint, the car shall pass these in order
 */
int blocks[MAX_COLUMNS][MAX_ROWS];

/****| FUNCTION DEFINITIONS |*************************************************/

/**
 * Gets the next action from the bot given the state of the car.
 *
 * @param car [in] the state of the car
 *
 * @return the action to be performed
 */
Action getAction(Car car) {
	Action action = {Pedal_NONE, Steering_NONE};

	/*
	 * TODO write your logic for the bot
	 *
	 * Example:
	 * Car nextCarState = compute(car, Pedal_GAS, Steering_RIGHT);
	 * if (....
	 */

	action.pedal = Pedal_GAS;
	action.steering = Steering_NONE;

	return action;
}
