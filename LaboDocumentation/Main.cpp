/**
 * @file Main.cpp
 * @author Sander Grielens
 * @brief Contains the entry function for the project
 */

#include "./Pad/Pad.h"
#include "./RoboInterface/Robot.h"
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
	Robot robert;

void deleterob(int a)
{
	delete &robert;
	exit(0);
}
int main(int argc, char *argv[]) {
	// Initialize wifistuff
	Client *client;
    	client = Client::getInstance();
    	Info data;
	//Robot robert;
	Pad weg;
	bool gepakt = true;
	int status;
	signal(SIGCLD, &deleterob);

	while(1)
	{
	       	data = client->getData();
		if(gepakt == true)
    		{
       			weg.calc(data.robx, data.roby, data.robhoek, data.doelx, data.doely);
	                cout << "Start Move" << endl;
       			robert.ride(weg.getAngle(), weg.getDistance());
        	        cout << "END Move" << endl;
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

