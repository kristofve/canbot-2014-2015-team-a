/** 
 * @file Main.cpp
 * @author Sander Grielens
 * @brief Contains the entry function for the project
 */

#include "./Pad/Pad.h"
#include "./RoboInterface/RoboInterface.h"
#include "./UDP/Client.h"
/*#include 
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
	Client *client;
    	client = Client::getInstance();
    	Info data;
	RoboInterface inter(-1, -1);
	Pad weg;
	bool gepakt = true;

	while(1)
	{
        	data = client->getData();

      
		if(gepakt == true)
    		{
       			weg.calc(data.robx, data.roby, data.robhoek, data.doelx, data.doely);
		        inter.setDistance(weg.getDistance());
			inter.setAngle(weg.getAngle());
			cout << "Start Move" << endl;
			inter.move(weg.getAngle(),weg.getDistance());
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
