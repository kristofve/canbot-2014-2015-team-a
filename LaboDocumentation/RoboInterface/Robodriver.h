#pragma once

#include <iostream>
#include <sstream>
#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <errno.h>

#include "wiringPi.h"
#include "wiringSerial.h"

#define FILENAME "/dev/ttyUSB0"
#define BAUDRATE 38400

#define TURNRATE 90
#define MOVERATE 100
#define SPEED 100
#define CMDSIZE 15

enum Action {STOP, LEFT, RIGHT, FORWARD, BACKWARD, OPEN, CLOSE, DISTANCE, POWER};

class Robodriver
{
    public:
        /**
        *@brief constructor
        */
        Robodriver();
        /**
        *@brief destructor
        *       closes the file-descriptor
        */
        ~Robodriver();
        /**
        *@brief executes the command
        *@param     type
        *           the requested action (see Action enum)
        *@param     distance
        *           travel distance
        *@return    0 on success, -1 on failure
        */
        int execute(Action type, float distance);


    private:
        char* buildCommand(Action type);
        int sendCommand(char* command);
        int setup();
        std::string toString(const int &number);
        int fd;

};
