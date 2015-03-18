/**
*	headerfile Pad.h
*	Sam Liekens
*	Declaratie van Pad object
*	prototype function 
*/
#ifndef _H_PAD
#define _H_PAD


#include <iostream>
#include <cmath>
//afstand tussen grid eenheden in mm
//bv 10 geeft een veld opgedeeld in cm²
#define GRIDRESOLUTION 1
#define PI 3.14159265

using namespace std;

class Pad{
		int angle;
		int distance;
public:
		Pad(){angle =0; distance = 0;}
		    void calc(int,int,int,int,int);
			int getDistance() {return distance;};
			int getAngle(){return angle;};
};

#endif
