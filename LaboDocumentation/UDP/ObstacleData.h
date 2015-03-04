/**
 * @file ObstacleData.h
 * @author Kevin Vancauwenbergh,Stijn Frans
 * @brief Declares the ObstacleData.h class, which describes an obscle
 * The intent is to create an array of such objects
 */

#ifndef OBSTACLEDATA_H
#define OBSTACLEDATA_H

#include <string>
#include <iostream>
#include "Point.h"

using namespace std;
/** @brief Class that creates a Obstacledata, Xpoint Ypoint of a can **/
class ObstacleData {
	/** The position of the obstacle **/
	int Obx, Oby;
public:
	/** @brief Default constructor **/
	ObstacleData();

	/** @brief Constructor with the location specified 
	 * @param 	int x
	 * 		The x coordinate 
	 * @param 	int y
	 * 		The y coordinate
	 * **/
	ObstacleData(int x,int y);

	/** @brief Setter for the x location
	 * @param 	int x
	 * 		The x coordinate **/
	void set_Obx(int x);

	/** @brief Setter for the y location 
	 * @param 	int y
	 * 		The y coordinate 
	 * **/
	void set_Oby(int y);

	/** @brief Getter for the x location
	 * @return The x coordinate of the object 
	 * **/
	int get_Obx();
	
	/** @brief Getter for the y location 
	 * @return The y coordinate of the object 
	 * **/
	int get_Oby();

	/** @brief Set the coordinates immediatly 
	 * @param 	int x
	 * 		The x coordinate
	 * @param 	int y
	 * 		The y coordinate
	 * */
	void set_Ob(int x,int y);

	/** @brief Debug printing function **/
	void print();

	/** @brief Debug function for filling in a location **/
	void FillWithDummyValues();
	
	/** @brief Converts the ObstacleData to a point
	 * @return Its location **/
	Point getPoint();
};

#endif
