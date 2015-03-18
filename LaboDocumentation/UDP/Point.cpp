/**
 * @file Point.cpp
 * @author Huysmans Bjorn, Kevin Vancauwenbergh, Bram Aerts
 * @brief Definition of this class, declaration found in Point.h
 */

#include "Point.h"

/** @brief Point class containing all functionality
 */

Point::Point(int a, int b){
	// Constructor
	setX(a);
	setY(b);
}

Point::Point(){
}

Point::~Point(){
	// Destructor
}

void Point::setX(int a){
	x = a;
}

int Point::getX(void){
	return x;
}

void Point::setY(int a){
	y = a;
}

int Point::getY(void){
	return y;
}

bool Point::isEqual(Point other) {
	if (other.getX() == this->getX() && other.getY() == this->getY())
		return true;
	else
		return false;
}

