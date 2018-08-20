/*
 * Default framwork implementation of the bot program.
 *
 * This includes the communication with the simulator through the standard input and
 * output.
 *
 * This file may be extended, but make sure that the communication scheme is intact,
 * otherwise the bot will not be able to communicate with the simulator.
 */

/****| INCLUDES |*************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <CarDynamics.h>
#include <Bot.h>

/****| MACRO DEFINITIONS |****************************************************/

/* The buffer size for reading the input */
#define BUFFER_SIZE 16384

/****| STATIC VARIABLE DECLARATIONS |*****************************************/

/* The actual car state */
static Car car;

/* Buffer used for communication with the simulator */
static char line_buffer[BUFFER_SIZE];

/****| STATIC FUNCTION DEFINITIONS *******************************************/

/**
 * Checks if a string begins with a prefix.
 *
 * @param string [in] the string
 * @param prefix [in] the prefix
 *
 * @return 0 if the string does not starts with the prefix, non-0 otherwise
 */
static boolean startsWith(char* string, char* prefix) {
	return !strncmp(string, prefix, strlen(prefix));
}

/****| MAIN FUNCTION DEFINITION **********************************************/

/**
 * Main function that implements the communication loop with the simulator.
 *
 * @return EXIT_SUCCESS always
 */
int main(void) {

    /* Fill the car state and the block array with 0 */
	memset(&car, 0, sizeof(car));
	memset(&blocks, 0, MAX_COLUMNS * MAX_ROWS * sizeof(int));

	/*
	 * Communication with the simulator
	 * The bot program shall continuously read complete lines from the standard input,
	 * then process the received message.
	 * In case the message is "get_action", the bot shall return the action to be
	 * performed by the simulator in the next tick.
	 *
	 * The following messages are transmitted by the simulator before the first tick:
	 * block_size
	 * racetrack_columns
	 * racetrack_rows
	 * block
	 * checkpoint
	 *
	 * The following messages are transmitted by the simulator before each tick:
	 * car_position
	 * car_direction
	 * car_speed
	 * car_steering_angle
	 *
	 * Before each tick the simulator asks for an action with the following message:
	 * get_action
	 */
	while(fgets(line_buffer, BUFFER_SIZE, stdin) != NULL) {

		if (startsWith(line_buffer, "block_size ")) {

		    /* The simulator sends the size of a block in pixels */
			sscanf((const char *) &line_buffer, "block_size %lf", &block_size);

		} else if (startsWith(line_buffer, "racetrack_columns ")) {

		    /* The simulator sends the number of columns on the track */
			sscanf((const char *) &line_buffer, "racetrack_columns %d", &racetrack_columns);

		} else if (startsWith(line_buffer, "racetrack_rows ")) {

		    /* The simulator sends the number of rows on the track */
			sscanf((const char *) &line_buffer, "racetrack_rows %d", &racetrack_rows);

		} else if (startsWith(line_buffer, "block ")) {

			int x,y;

			/*
			 * The simulator sends the position of a wall block.
			 * Note that free block positions are not transmitted at all, the track should be initialized
			 * with all blocks as free blocks.
			 */
			sscanf((const char *) &line_buffer, "block %d %d", &x, &y);
			blocks[x][y] = -1;

		} else if (startsWith(line_buffer, "checkpoint ")) {

		    int id, x, y;

		    /* The simulator sends the position of a checkpoint with the given ID */
			sscanf((const char *) &line_buffer, "checkpoint %d %d %d", &id, &x, &y);
			blocks[x][y] = id;

		} else if (startsWith(line_buffer, "car_position ")) {

		    /* The simulator sends the current position of the car */
			sscanf((const char *) &line_buffer, "car_position %lf %lf", &car.position.x, &car.position.y);

		} else if (startsWith(line_buffer, "car_direction ")) {

		    /* The simulator sends the current direction of the car */
			sscanf((const char *) &line_buffer, "car_direction %lf", &car.direction);

		} else if (startsWith(line_buffer, "car_speed ")) {

		    /* The simulator sends the current speed of the car */
			sscanf((const char *) &line_buffer, "car_speed %lf", &car.speed);

		} else if (startsWith(line_buffer, "car_steering_angle ")) {

		    /* The simulator sends the current steering angle of the car, relative to the current direction */
			sscanf((const char *) &line_buffer, "car_steering_angle %lf", &car.steeringAngle);

		} else if (startsWith(line_buffer, "get_action")) {

		    /*
		     * The simulator requests an action from the bot program.
		     * The expected responses are
		     * <gas_status> <steer_status>
		     * where <gas_status> may be: "brake", "gas" or "nop", and
		     * <steer_status> may be "left", "right" or "nop"
		     *
		     * The response shall end with a newline character.
		     *
		     * Please note that the simulator processes only one line after each get_action command,
		     * therefore if more lines are transmitted, these lines will be consumed after the next
		     * get_action command from the input buffer and the bot will not work properly.
		     */
			Action action = getAction(car);

			switch (action.pedal) {
				case Pedal_BRAKE:
					printf("brake ");
					break;
				case Pedal_GAS:
					printf("gas ");
					break;
				case Pedal_NONE:
				default:
					printf("nop ");
					break;
			}

			switch (action.steering) {
				case Steering_LEFT:
					printf("left\n");
					break;
				case Steering_RIGHT:
					printf("right\n");
					break;
				case Steering_NONE:
				default:
					printf("nop\n");
					break;
			}

			fflush(stdout);

		} else if (startsWith(line_buffer, "exit")) {

		    /* End of simulation, the program shall exit */
			break;
		}
	}

	return EXIT_SUCCESS;
}
