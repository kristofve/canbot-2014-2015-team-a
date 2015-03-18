#include <iostream>

class RoboInterface{
	double distance;
	double angle;
	bool collected;

	public:
		RoboInterface(int,int);
		double getDistance();
		double getAngle();
		bool isCollected();
		void setDistance(int myDistance);
		void setAngle(int myAngle);
		void setCollected(bool myCollected);
		void printCan();
		void move();
};
