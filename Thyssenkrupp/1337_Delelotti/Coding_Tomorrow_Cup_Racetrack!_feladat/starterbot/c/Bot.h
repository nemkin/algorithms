#ifndef BOT_H
#define BOT_H

/****| INCLUDES |*************************************************************/

#include <CarDynamics.h>

/****| MACRO DEFINITIONS |****************************************************/

/* Maximum width (x dimension) of the race track */
#define MAX_COLUMNS     30

/* Maximum height (y dimension) of the race track */
#define MAX_ROWS        30

/****| TYPE DECLARATIONS |****************************************************/

/* Possible actions for a bot to perform per tick */
typedef struct Action {

	/* The action with the pedal */
	Pedal pedal;

	/* The action with the steering angle */
	Steering steering;

} Action;

/****| EXTERN VARIABLE DECLARATIONS |*****************************************/

/* The (square) block size length */
extern double block_size;

/* The number of columns of the race track (x dimension) */
extern int racetrack_columns;

/* The number of rows of the race track (y dimension) */
extern int racetrack_rows;

/*
 * The blocks of the race track. *
 * 0    - empty block, the car can use it
 * -1   - wall block, the car shall avoid these
 * 1..  - checkpoint, the car shall pass these in order
 */
int blocks[MAX_COLUMNS][MAX_ROWS];

/****| EXTERN FUNCTION DECLARATIONS |*****************************************/

/**
 * Gets the next action from the bot given the state of the car.
 *
 * @param car [in] the state of the car
 *
 * @return the action to be performed
 */
extern Action getAction(Car car);

#endif /* BOT_H */
