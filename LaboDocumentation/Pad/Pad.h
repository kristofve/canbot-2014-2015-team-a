/**
*	headerfile Pad.h
*	Sam Liekens
*	Declaratie van Pad object
*	prototype function 
*/
#include<iostream>
#include<cmath>
//afstand tussen grid eenheden in mm
//bv 10 geeft een veld opgedeeld in cm²
#define GRIDRESOLUTION 10
#define PI 3.14159265

using namespace std;

class Pad{
		int angle = 0;
		int distance = 0;
public:
		    void calc(int,int,int,int,int);
			int getDistance() {return distance;};
			int getAngle(){return angle;};
};


