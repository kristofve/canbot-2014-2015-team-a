#pragma once

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include "Robodriver.h"

class Robot
{
    public:
        /**
        *@brief constructor
        */
        Robot();
        /**
        *@brief destructor
        */
        ~Robot();
        /**
        *@brief grab the can
        *@return 0 on success, -1 on failure
        *
        */
        int grab();
        /**
        *@brief drop the can
        *@return 0 on success, -1 on failure
        *
        */
        int drop();
        /**
        *@brief move the robot in the desired direction and angle
        *@param     angle
        *           the angle the robot has to rotate over
        *@param     distance
        *           the distance the robot has to drive
        *@return    0 on success, -1 on failure
        */
        int ride(float angle, float distance);
        /**
        *@brief read the distance sensor's information
        *@return    the distance towards the object, -2 on failure
        */
        int readSensor();
        /**
        *@brief Quick startup test.
        *@return    0 on success, -1 on failure
        */
        int startupTest();


    private:
        int setup();
        int turnLeft(float degrees);
        int turnRight(float degrees);
        int moveForward(float distance);
        int moveBackward(float distance);

        Robodriver* driver;


};
