/**
 * @file RobotData.h
 * @author Kevin Vancauwenbergh,Stijn Frans
 * @brief Declares the RobotData class, which contains the data of our robot send by the vision team
 */

#ifndef ROBOTDATA_H
#define ROBOTDATA_H

#include <string>
#include <iostream>
using namespace std;
/**
 * @brief Defines the class 'RobotData', Which will contain the position and angle of the robot aswell as the position of the garage and the can to pick up.
 */

class RobotData {
	/** The x location of the robot **/
	int robotX;

	/** The y location of the robot **/
	int robotY;

	/** The angle, in degrees, the robot makes with the bottom **/
	int angle;

public:
		/**
        * @brief Constructor of the class RobotData.
		* @param int Xposition
		*@param int Yposition
		*@param int angle
		 */
	RobotData(int x,int y, int angle);
	/**
		 * @brief Constructor of the class RobotData.
		 */
	RobotData();
		/**
		 * @brief Getter for Xposition robot.
		 *
		 * @return	integer Xposition robot.
		 */
	int getX();
         /**
		 * @brief Getter for Yposition robot.
		 *
		 * @return	integer Yposition robot.
		 */
	int getY();
        /**
		 * @brief Getter for Angle robot.
		 *
		 * @return	integer Angle robot.
		 */
	int getAngle();

	/**
		 * @brief Setter for Xposition robot.
		 *
		 * @param	int Xposition robot.
		 */

	void setX(int x);
	/**
		 * @brief Setter for Yposition robot.
		 *
		 * @param	int Yposition robot.
		 */

	void setY(int y);
	/**
		 * @brief Setter for Angle robot.
		 *
		 * @param	int Angle robot.
		 */

	void setAngle(int a);

         /**
		 * @brief setter for robot.
		 *
		 */
	void setRobot(int x,int y,int a);
        /**
		 * @brief Print function for all the data of robotdata
		 */

	void print();
         /**
		 * @brief fills the Robot with dummyvalues
		 */

	void FillWithDummyValues();
};

#endif
