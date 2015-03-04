/**
 * @file Point.h
 * @author Huysmans Bjorn, Kevin Vancauwenbergh, Beam Aerts
 * @brief Declaration of the Point class. This class holds the information about
 * a specific point in the world (2D or pixel). It has an x and a y value.
 */

#ifndef POINT_H
#define	POINT_H

/** @brief Point class containing info about a specific point
 */
class Point {
    int x, y;
  public:
	/** @brief Constructor */
	Point();



	/** @brief Destructor */
	~Point(void);

	/** @brief Destructor with the two points specifief
	 * @param The x location
	 * @param The y location **/
	Point(int a, int b);

	/**
	 * @brief Setter for the x-value (int)
	 *
	 * @param	int a
	 *		Value x to be set
	 */
	void setX(int);

	/**
	 * @brief Getter for the x-value
	 *
	 * @return value of x
	 */
	int getX(void);

	/**
	 * @brief Setter for the y-value
	 *
	 * @param	int a
	 *		Value y to be set
	 */
	void setY(int);

	/**
	 * @brief Getter for the y-value
	 *
	 * @return value of y
	 */
	int getY(void);

	/**
	 * @brief Compares two points
	 * 
	 * @return True if equal, false if nt equal
	 */
	bool isEqual(Point);
};

#endif
