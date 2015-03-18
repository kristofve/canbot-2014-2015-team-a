#include "RoboInterface.h"
#include "Robo.cpp"
#include <iostream>

RoboInterface::RoboInterface(int myDistance, int myAngle) {
	distance = myDistance;
	angle = myAngle;
	collected = false;
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
	Robo robo(30);
	robo.move(angle,distance);
}
