#include "RoboInterface.h"
#include <iostream>

RoboInterface::RoboInterface(int myDistance, int myAngle) {
        distance = myDistance;
        angle = myAngle;
        collected = false;
	robo = Robo(30);
}

void RoboInterface::setDistance(int myDistance){
        distance = myDistance;
}

void RoboInterface::setAngle(int myAngle){
        angle = myAngle;
}

void RoboInterface::setCollected(bool myCollected){
        collected = myCollected;
}
void RoboInterface::move(){
        robo.move(angle,distance);
}

