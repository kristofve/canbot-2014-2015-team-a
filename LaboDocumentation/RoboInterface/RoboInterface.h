#include <iostream>
#include "Robo.h"
#ifndef _H_ROBOINTERFACE
#define _H_ROBOINTERFACE

class RoboInterface{
        int distance;
        int angle;
        bool collected;
	Robo robo;

        public:
                RoboInterface(int,int);
                int getDistance() {return distance;}
                int getAngle() {return angle;}
                bool isCollected() {return collected;}
                void setDistance(int myDistance);
                void setAngle(int myAngle);
                void setCollected(bool myCollected);
                void printCan() {std::cout<<"distance: " <<getDistance()<< " angle: " << getAngle()<< " isCollected? " << isCollected() << "\n";}
                void move();
};
#endif
