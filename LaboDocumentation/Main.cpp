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
	bool gepakt = false;
	int status;
	signal(SIGINT, &deleterob);


	for(int i = 0; i < 100; i++)		//Initialiseren van de servogrijper.
	{
		int resultaat = robert.drop();
	}
	cout << "Opening the Claw." << endl;
	sleep(2);

	while(1)
	{
	       	data = client->getData();
		if(gepakt == false)
    		{
       			weg.calc(data.robx, data.roby, data.robhoek, data.doelx, data.doely);
       			//weg.calc(1,1,45, 500, 650);
	                cout << "Start Move" << endl;
       			robert.ride(weg.getAngle(), weg.getDistance());
        	        cout << "END Move" << endl;
			cout << weg.getDistance()<<endl;
			if(weg.getDistance() < 50 && weg.getAngle() <10 && weg.getAngle() > -10)
			{
				int res=robert.grab();
				for(int i = 0; i < 100; i++)		//Initialiseren van de servogrijper.
				{
					int resultaat = robert.grab();
				}
				gepakt=true;
			}
		}
    		else
    		{
       			weg.calc(data.robx, data.roby, data.robhoek, data.garx, data.gary);
       			//weg.calc(1,1,45, 500, 650);
	                cout << "Start Move" << endl;
       			robert.ride(weg.getAngle(), weg.getDistance());
        	        cout << "END Move" << endl;
			cout << weg.getDistance()<<endl;
			if(weg.getDistance() < 40)
			{
				int resultaat = robert.drop();
				for(int i = 0; i < 100; i++)		//Initialiseren van de servogrijper.
				{	
					int resultaat = robert.drop();
				}
				deleterob(0);
			}
		}
	}

	return 0;
}

