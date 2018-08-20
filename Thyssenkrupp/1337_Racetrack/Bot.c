/*
 * This source file is a skeleton for a bot implementation. In each tick the
 * getAction() function is triggered by the simulator with the car's actual
 * position and direction. The function must return an action for the next tick.
 */

#include <Bot.h>
#include <CarDynamics.h>
#include <Util.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

/*int block_goal[5][6] = {{0,3,3,3,3,0},
                        {0,0,0,0,2,3},
                        {1,0,0,0,0,2},
                        {0,0,0,1,1,2},
                        {0,1,1,2,0,0},
                        };*/

/****| FUNCTION DEFINITIONS |*************************************************/

const double pi = 3.14159265358979323;

/*void loglog(const char* s) {
    FILE *fp = fopen("car-out.txt", "a");
    if (fp != NULL) {
        fprintf(fp, "%s\n", s);
        fclose(fp);
    }
}

void loglogi(int x) {
    FILE *fp = fopen("car-out.txt", "a");
    if (fp != NULL) {
        fprintf(fp, "%d ", x);
        fclose(fp);
    }
}

void loglogd(double x) {
    FILE *fp = fopen("car-out.txt", "a");
    if (fp != NULL) {
        fprintf(fp, "%lf ", x);
        fclose(fp);
    }
}*/

double distance(Vector v, Vector u) {
    return (v.x-u.x)*(v.x-u.x) + (v.y-u.y)*(v.y-u.y);
}

double atg(double x, double y) {

    if (x==0.0) {
        if (y<0.0)
            return 3*pi/2;
        else
            return pi/2;
    }
    if (x>0) {
        return atan(y/x) >=0.0 ? atan(y/x) : atan(y/x) + 2*pi;
    }
    else {
        return atan(y/x) + pi;
    }
}

double dirdist(double d, double f) {
    double r = d-f;
    if (isNearZero(r))
        return 0.0;
    if (r<0)
        r = r+2*pi;
    return r;
}


int cgoalpoint = 0;
int ngoalpoints = 0;
Vector goalpoints[10000];
double goaldists[10000];
int goals_initialized = 0;

double cornerdelay = -1; // from center of square



int bfs(int startx, int starty, int goalx, int goaly, int _src) {

    /*FILE *fp = fopen("car-out.txt", "a");
    if (fp != NULL) {
        fprintf(fp, "bfs: %d %d %d %d\n", startx, starty, goalx, goaly);
        fclose(fp);
    }*/

    int volt[MAX_COLUMNS][MAX_ROWS];
    int dst[MAX_COLUMNS][MAX_ROWS];
    int src[MAX_COLUMNS][MAX_ROWS];

    int i,j;

    int ql=1, qpos=0;
    int qx[MAX_COLUMNS*MAX_ROWS];
    int qy[MAX_COLUMNS*MAX_ROWS];
    qx[0] = startx;
    qy[0] = starty;


    // init
    for (i=0; i<racetrack_columns; i++) {
        for (j=0; j<racetrack_rows; j++) {
            volt[i][j] = 0;
            dst[i][j] = 100000;
            src[i][j] = -1;
        }
    }

    dst[startx][starty] = 0;
    volt[startx][starty] = 1;
    src[startx][starty] = _src;


    //loglog("starting bfs...");
    // bfs
    while (qpos != ql) {
        int cx = qx[qpos];
        int cy = qy[qpos];
        if (cx > 0 && blocks[cx-1][cy] >= 0 && !volt[cx-1][cy] && src[cx][cy] != 1) {
            qx[ql] = cx-1;
            qy[ql] = cy;
            ql++;
            volt[cx-1][cy] = 1;
            src[cx-1][cy] = 3;
            dst[cx-1][cy] = dst[cx][cy]+1;
        }
        if (cy > 0 && blocks[cx][cy-1] >= 0 && !volt[cx][cy-1] && src[cx][cy] != 0) {
            qx[ql] = cx;
            qy[ql] = cy-1;
            ql++;
            volt[cx][cy-1] = 1;
            src[cx][cy-1] = 2;
            dst[cx][cy-1] = dst[cx][cy]+1;
        }
        if (cx < racetrack_columns-1 && blocks[cx+1][cy] >= 0 && !volt[cx+1][cy] && src[cx][cy] != 3) {
            qx[ql] = cx+1;
            qy[ql] = cy;
            ql++;
            volt[cx+1][cy] = 1;
            src[cx+1][cy] = 1;
            dst[cx+1][cy] = dst[cx][cy]+1;
        }
        if (cy < racetrack_rows-1 && blocks[cx][cy+1] >= 0 && !volt[cx][cy+1] && src[cx][cy] != 2) {
            qx[ql] = cx;
            qy[ql] = cy+1;
            ql++;
            volt[cx][cy+1] = 1;
            src[cx][cy+1] = 0;
            dst[cx][cy+1] = dst[cx][cy]+1;
        }
        qpos++;
    }
    //loglog("bfs step 1 ok");

    /*fp = fopen("car-out.txt", "a");
    if (fp != NULL) {
        fprintf(fp, "volt:\n");
        int i,j;
        for (i=0; i<racetrack_columns; i++) {
            for (j=0; j<racetrack_rows; j++) {
                fprintf(fp, "%d ", volt[i][j]);
            }
            fprintf(fp, "\n");
        }
        fprintf(fp, "\n");

        fprintf(fp, "dist:\n");
        for (i=0; i<racetrack_columns; i++) {
            for (j=0; j<racetrack_rows; j++) {
                fprintf(fp, "%d ", dst[i][j]);
            }
            fprintf(fp, "\n");
        }
        fprintf(fp, "\n");

        fprintf(fp, "src:\n");
        for (i=0; i<racetrack_columns; i++) {
            for (j=0; j<racetrack_rows; j++) {
                fprintf(fp, "%d ", src[i][j]);
            }
            fprintf(fp, "\n");
        }
        fprintf(fp, "\n");


        fclose(fp);
    }*/

    if (!volt[goalx][goaly])
        exit(-23);

    int roadlen = 0;
    int roadx[MAX_COLUMNS*MAX_ROWS];
    int roady[MAX_COLUMNS*MAX_ROWS];

    roadx[0] = goalx;
    roady[0] = goaly;
    roadlen = 1;
    int cx = goalx, cy = goaly;



    while (cx != startx || cy != starty) {
        /*fp = fopen("car-out.txt", "a");
        if (fp != NULL) {
            fprintf(fp, "  back route: %d %d %d\n", cx, cy, src[cx][cy]);
            fclose(fp);
        }*/
        switch (src[cx][cy]) {
            case 0: cy--; break;
            case 1: cx--; break;
            case 2: cy++; break;
            case 3: cx++; break;
            default: exit(-2);
        }
        roadx[roadlen] = cx;
        roady[roadlen] = cy;
        roadlen++;
    }


    /*fp = fopen("car-out.txt", "a");
    if (fp != NULL) {
        fprintf(fp, "road %d %d -> %d %d\n", startx, starty, goalx, goaly);
        int i;
        for (i=roadlen-1; i>=0; i--) {
            fprintf(fp, "%d %d\n", roadx[i], roady[i]);
        }
        fprintf(fp, "\n\n");
        fclose(fp);
    }*/

    for (i=roadlen-2; i>=1; i--) {
        int pdir, ndir;
        if (roadx[i+1] == roadx[i]-1) // right
            pdir = 1;
        if (roadx[i+1] == roadx[i]+1) // left
            pdir = 3;
        if (roady[i+1] == roady[i]-1) // up
            pdir = 0;
        if (roady[i+1] == roady[i]+1) // right
            pdir = 2;

        if (roadx[i-1]-1 == roadx[i]) // right
            ndir = 1;
        if (roadx[i-1]+1 == roadx[i]) // left
            ndir = 3;
        if (roady[i-1]-1 == roady[i]) // up
            ndir = 0;
        if (roady[i-1]+1 == roady[i]) // right
            ndir = 2;

        double centx = roadx[i] * block_size + block_size/2;
        double centy = roady[i] * block_size + block_size/2;
        if ((pdir == 2 && ndir == 1) || (pdir == 3 && ndir == 0)) {
            goalpoints[ngoalpoints]  = (Vector){centx+cornerdelay, centy+cornerdelay};
            goaldists[ngoalpoints] = 2500.0;
            ngoalpoints++;
            //loglog("new goal point found (jf)");
            //loglogi(roadx[i]);
            //loglogi(roady[i]);
            //loglog("");

        }
        if ((pdir == 3 && ndir == 2) || (pdir == 0 && ndir == 1)) {
            goalpoints[ngoalpoints]  = (Vector){centx+cornerdelay, centy-cornerdelay};
            goaldists[ngoalpoints] = 2500.0;
            ngoalpoints++;
            //loglog("new goal point found (ja)");
            //loglogi(roadx[i]);
            //loglogi(roady[i]);
            //loglog("");
        }
        if ((pdir == 1 && ndir == 2) || (pdir == 0 && ndir == 3)) {
            goalpoints[ngoalpoints]  = (Vector){centx-cornerdelay, centy-cornerdelay};
            goaldists[ngoalpoints] = 2500.0;
            ngoalpoints++;
            //loglog("new goal point found (ba)");
            //loglogi(roadx[i]);
            //loglogi(roady[i]);
            //loglog("");
        }
        if ((pdir == 1 && ndir == 0) || (pdir == 2 && ndir == 3)) {
            goalpoints[ngoalpoints]  = (Vector){centx-cornerdelay, centy+cornerdelay};
            goaldists[ngoalpoints] = 2500.0;
            ngoalpoints++;
            //loglog("new goal point found (bf)");
            //loglogi(roadx[i]);
            //loglogi(roady[i]);
            //loglog("");
        }

        if (pdir==ndir) {
            goalpoints[ngoalpoints]  = (Vector){centx, centy};
            goaldists[ngoalpoints] = 5000.0;
            ngoalpoints++;
            //loglog("new goal point added (center)");
            //loglogi(roadx[i]);
            //loglogi(roady[i]);
            //loglog("");
        }


        /*fp = fopen("car-out.txt", "a");
        if (fp != NULL) {
            fprintf(fp, "going on back route: %d %d (%d %d, %d %d) p: %d n: %d\n", roadx[i], roady[i], roadx[i-1], roady[i-1], roadx[i+1], roady[i+1],  pdir, ndir);
            fclose(fp);
        }*/

    }

    goalpoints[ngoalpoints]  = (Vector){goalx * block_size + block_size/2, goaly * block_size + block_size/2};
    goaldists[ngoalpoints] = 5000.0;
    ngoalpoints++;


    return src[goalx][goaly];

}

void initgoals() {
    if (goals_initialized)
        return;
    cornerdelay = block_size/3;
    /*Vector vv = {75.,75.};
    goalpoints[0] = vv;
    goalpoints[1] = (Vector){75+cornerdelay, 375-cornerdelay};
    goalpoints[2] = (Vector){225-cornerdelay, 375+cornerdelay};
    goalpoints[3] = (Vector){225+cornerdelay, 675-cornerdelay};
    goalpoints[4] = (Vector){375, 675};
    goalpoints[5] = (Vector){525-cornerdelay, 675-cornerdelay};
    goalpoints[6] = (Vector){525+cornerdelay, 525+cornerdelay};
    goalpoints[7] = (Vector){825-cornerdelay, 525-cornerdelay};
    goalpoints[8] = (Vector){825, 375};
    goalpoints[9] = (Vector){825-cornerdelay, 225+cornerdelay};
    goalpoints[10] = (Vector){675+cornerdelay, 225-cornerdelay};
    goalpoints[11] = (Vector){675-cornerdelay, 75+cornerdelay};
    goalpoints[12] = (Vector){75,75};*/
    goals_initialized = 1;

    /*FILE *fp = fopen("car-out.txt", "a");
    if (fp != NULL) {
        int i,j;
        fprintf(fp, "blocks:\n");
        for (i=0; i<racetrack_columns; i++) {
            for (j=0; j<racetrack_rows; j++) {
                fprintf(fp, "%d ", blocks[i][j]);
            }
            fprintf(fp, "\n");
        }
        fprintf(fp, "\n\n");
        fprintf(fp, "starting all bfs-s...\n");
        fclose(fp);
    }*/

    int cx=0, cy=0;
    int cp,i,j;
    int _src = 0;
    for (cp=1; cp<=MAX_COLUMNS*MAX_ROWS; cp++) {
        for (i=0; i<MAX_COLUMNS; i++) {
            for (j=0; j<MAX_ROWS; j++) {
                if (blocks[i][j] == cp) {
                    _src = bfs(cx, cy, i, j, _src);
                    cx = i;
                    cy = j;
                }
            }
        }
    }
    /*fp = fopen("car-out.txt", "a");
    if (fp != NULL) {
        fprintf(fp, "goals:\n");
        int i,j;
        for (i=0; i<ngoalpoints; i++) {
            fprintf(fp, "%lf %lf, ", goalpoints[i].x, goalpoints[i].y);
        }
        fprintf(fp, "\n\n");
        fclose(fp);
    }*/
}




/**
 * Gets the next action from the bot given the state of the car.
 *
 * @param car [in] the state of the car
 *
 * @return the action to be performed
 */
Action getAction(Car car) {
	Action action = {Pedal_GAS, Steering_NONE};

	/*
	 * TODO write your logic for the bot
	 *
	 * Example:
	 * Car nextCarState = compute(car, Pedal_GAS, Steering_RIGHT);
	 * if (....
	 */

	 if (!goals_initialized)
            initgoals();


	int block_x = car.position.x / block_size;
	int block_y = car.position.y / block_size;

	//int c_goal = block_goal[block_y][block_x];
	double goal_x, goal_y;

	// negyzetek szele
	/*
	if (c_goal == 0) {
        // fel
        goal_x = block_x*block_size + block_size/2;
        goal_y = (block_y+1) * block_size;
	}
	if (c_goal == 1) {
        // jobbra
        goal_x = (block_x+1)*block_size;
        goal_y = block_y * block_size + block_size/2;
	}
	if (c_goal == 2) {
        // le
        goal_x = block_x*block_size + block_size/2;
        goal_y = (block_y) * block_size;
	}
	if (c_goal == 3) {
        // balra
        goal_x = (block_x)*block_size;
        goal_y = block_y * block_size + block_size/2;
	}*/
	while (cgoalpoint < ngoalpoints && distance(car.position, goalpoints[cgoalpoint]) < goaldists[cgoalpoint]) {
        cgoalpoint++;
	}
	if (cgoalpoint >= ngoalpoints)
        return (Action){Pedal_BRAKE, Steering_NONE};

    goal_x = goalpoints[cgoalpoint].x;
    goal_y = goalpoints[cgoalpoint].y;
	Vector gv = createVector(goal_x, goal_y);

    // distance
	//Vector gv = createVector(goal_x, goal_y);
	/*double cdist = distance(car.position, gv);
	double mndist;

	Car nextCarStateLeft = compute(car, Pedal_GAS, Steering_RIGHT);
	if (distance(nextCarStateLeft.position, gv) < mndist || 1) {
        action.steering = Steering_LEFT;
        mndist = distance(nextCarStateLeft.position, gv);
    }

    Car nextCarStateRight = compute(car, Pedal_GAS, Steering_LEFT);
	if (distance(nextCarStateRight.position, gv) < mndist) {
        action.steering = Steering_RIGHT;
        mndist = distance(nextCarStateRight.position, gv);
	}


    Car nextCarStateNone = compute(car, Pedal_GAS, Steering_NONE);
    nextCarStateNone.position.x = (nextCarStateLeft.position.x + nextCarStateRight.position.x)/2;
    nextCarStateNone.position.y = (nextCarStateLeft.position.y + nextCarStateRight.position.y)/2;
	if (distance(nextCarStateNone.position, gv) < mndist) {
        action.steering = Steering_NONE;
        mndist = distance(nextCarStateNone.position, gv);
	}
    */

    // angle
    double goaldir = atg(goal_x - car.position.x, goal_y - car.position.y);
    double cdir = car.direction;// + car.steeringAngle;
    while (cdir<0) cdir += 2*pi;
    while (cdir>=2*pi) cdir -= 2*pi;


    if (dirdist(cdir, goaldir) < 0.01 )
        action.steering = Steering_NONE;
    else if (dirdist(cdir, goaldir) <= pi )
        action.steering = Steering_RIGHT;
    else
        action.steering = Steering_LEFT;

    if (dirdist(cdir, goaldir) > pi/2 && dirdist(cdir, goaldir) < 3*pi/2)
        action.pedal = Pedal_BRAKE;

    /*if (distance(car.position, gv) < 1000.0) {
        if (car.steeringAngle > 0.05)
            action.steering = Steering_RIGHT;
        else if (car.steeringAngle < -0.05)
            action.steering = Steering_LEFT;
        else
            action.steering = Steering_NONE;
    }*/

    if (car.speed > 40.0)
        action.pedal = Pedal_NONE;
    /*if (action.steering == Steering_NONE || car.speed < 0.5)
        action.pedal = Pedal_GAS;
    else if (car.steeringAngle < 0.04)
        action.pedal = Pedal_NONE;
    else
        action.pedal = Pedal_BRAKE;*/


    /*FILE *fp = fopen("car-out.txt", "a");
    if (fp != NULL) {
        //Vector uv = unitVector(1.570796);
        //fprintf(fp, "uv: %lf %lf\n", uv.x, uv.y);
        fprintf(fp, "pos: %d %d\n", block_x, block_y);
        fprintf(fp, "car: %lf %lf spd: %lf turn: %lf %lf\n", car.position.x, car.position.y, car.speed, car.direction, car.steeringAngle);
        //fprintf(fp, "dist: %lf %lf %lf %lf\n", cdist, distance(nextCarStateLeft.position, gv), distance(nextCarStateRight.position, gv), mndist);
        fprintf(fp, "goal: %lf %lf (%d)\n", goal_x, goal_y, cgoalpoint);
        //fprintf(fp, "left pos: %lf %lf dir: %lf\n", nextCarStateLeft.position.x, nextCarStateLeft.position.y, nextCarStateLeft.direction);
        //fprintf(fp, "rght pos: %lf %lf dir: %lf\n", nextCarStateRight.position.x, nextCarStateRight.position.y, nextCarStateRight.direction);
        //fprintf(fp, "none pos: %lf %lf dir: %lf\n", nextCarStateNone.position.x, nextCarStateNone.position.y, nextCarStateNone.direction);
        fprintf(fp, "gd: %lf cd: %lf dirdist: %lf\n", goaldir, cdir, dirdist(cdir, goaldir));
        fprintf(fp, "dist: %lf\n", distance(car.position, gv));
        fprintf(fp, "action: %s %s\n\n", action.pedal == Pedal_GAS ? "gas" : (action.pedal == Pedal_BRAKE ? "brake" : "none"),
                                        action.steering == Steering_LEFT ? "left" : (action.steering == Steering_RIGHT ? "right" : "none"));
        fclose(fp);
    }*/

	return action;
}
