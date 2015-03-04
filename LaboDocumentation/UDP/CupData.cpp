/**
 * @file ObstacleData.cpp
 * @author Kevin Vancauwenbergh,Stijn Frans
 * @brief Defines the functions declared in ObstacleData.h
 */

#include "ObstacleData.h"

ObstacleData::ObstacleData() {
	Obx = 0;
	Oby = 0;
}

ObstacleData::ObstacleData(int x, int y)
{
	Obx = x;
	Oby = y;
}

void ObstacleData::set_Obx(int x)
{
	Obx = x;
}

void ObstacleData::set_Oby(int y)
{
	Obx = y;
}

int ObstacleData::get_Obx()
{ 
	return Obx; 
}
int ObstacleData::get_Oby()
{ 
	return Oby; 
}

void ObstacleData::set_Ob(int x,int y)
{
	Obx = x;
	Oby = y;
}

void ObstacleData::print()
{
cout 	<< "Obstakel:" << endl << "pos x:"  << Obx << endl 
			<< "pos y:" << Oby << endl;
}

void ObstacleData::FillWithDummyValues()
{
	Obx = 25;
	Oby = 29;
}

Point ObstacleData::getPoint() {
	return Point(get_Obx(), get_Oby());
}
