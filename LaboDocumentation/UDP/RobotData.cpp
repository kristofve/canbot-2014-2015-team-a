/**
 * @file RobotData.cpp
 * @author Kevin Vancauwenbergh,Stijn Frans
 * @brief Defines the functions declared in RobotData.h
 */
#include "RobotData.h"


RobotData::RobotData(int x, int y, int angle){
	robotX = x;
	robotY = y;
	angle = angle;
}
RobotData::RobotData() {
	robotX = robotY = angle = 0;
}

void RobotData::FillWithDummyValues() {
	robotX = 120;
	robotY = 100;
	angle = 45;
}

int RobotData::getX()
{
	return robotX;
}
int RobotData::getY()
{
	return robotY;
}
void RobotData::setX(int x)
{
	robotX= x;
}
void RobotData::setY(int y)
{
	robotY = y;
}
int RobotData::getAngle()
{
	return angle;
}
void RobotData::setAngle(int a)
{
	angle = a;
}
void RobotData::setRobot(int x, int y, int angle)
{
	robotX = x;
	robotY = y;
	angle = angle;
}

void RobotData::print()
{
	cout 	<< "Robot:" << endl << "\tpos x:"  << robotX << endl
			<< "\tpos y:" << robotY << endl << "\tangle:" << angle << endl;
}

