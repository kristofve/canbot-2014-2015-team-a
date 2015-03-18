/** 
 * @file Main.cpp
 * @author Sander Grielens
 * @brief Contains the entry function for the project
 */

#include "Pad.h"
#include "RoboInterface.h"
/*#include 
#include 
#include
#include 
#include 
#include */
#include <string.h>
#include <vector>

using namespace std;

/** @brief The entry function for the project 
 *  @return 0 is no error occured	
 * **/
int main(int argc, char *argv[]) {
	// Initialize wifistuff
	// Klasse van Robot, Garage en Blikje declareren
	/*RobotData r_d();
	CarHouseData ch_d();
	CupData c_d();*/
	RoboInterface inter(-1, -1);
	Pad weg;
bool gepakt = true;
	while(1)
	{

      
    if(gepakt == true)
    {
       weg.calc(1, 1, 20, 300, 158);
       inter.setDistance(weg.getDistance());
	inter.setAngle(weg.getAngle());
	cout << "Start Move" << endl;
	inter.move();
	cout << "END Move" << endl;
	inter.printCan();
    }
    /*else
    {
       weg->calc(r_d->getX(), r_d->getY(), r_d->getAngle(), c_d->getX(), c_d->getY());
       cout << "afstand:" << weg->getDistance();
       cout << "hoek:" << weg->getAngle();
       // blikje->set();
    }*/
	}	
	
	return 0;
}
