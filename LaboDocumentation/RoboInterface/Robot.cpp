#include "Robot.h"
using namespace std;

Robot::Robot()
{
    printf("Hi, I'm a robot.\n If a robot already exists, something has gone horribly wrong.\n Otherwise, congratulations!\n");
    setup();
}

Robot::~Robot()
{
    printf("Bye!\n");
    delete driver;
}

int Robot::grab()
{
    printf("Oooohhh, the clawwwww...\n");
    return driver->execute(CLOSE, 0);
}

int Robot::drop()
{
    printf("Drop it like it's hot. \n");
    return driver->execute(OPEN, 0);
}

int Robot::ride(float angle, float distance)
{
    int turnSuccess, rideSuccess;
    printf("Turning over %f degrees and moving over %f distance. \n",angle,distance);
    if (angle < 0)
    {
        turnSuccess = turnLeft(abs(angle));
    }
    else
    {
        turnSuccess = turnRight(abs(angle));
    }
    if (distance < 0)
    {
        rideSuccess = moveBackward(abs(distance));
    }
    else
    {
        rideSuccess = moveForward(abs(distance));
    }

    if (/*rideSuccess != 0 || */turnSuccess != 0)
    {
        return -1;
    }
    return 0;
}

int Robot::readSensor()
{
    return driver->execute(DISTANCE, 0);
}

int Robot::startupTest()
{
    return driver->execute(POWER, 0);
}

int Robot::setup()
{
    driver = new Robodriver();
    return 0;
}

int Robot::turnLeft(float degrees)
{
    return driver->execute(LEFT, degrees);
}

int Robot::turnRight(float degrees)
{
    return driver->execute(RIGHT, degrees);
}

int Robot::moveForward(float distance)
{
    return driver->execute(FORWARD, distance);
}

int Robot::moveBackward(float distance)
{
    return driver->execute(BACKWARD, distance);
}
