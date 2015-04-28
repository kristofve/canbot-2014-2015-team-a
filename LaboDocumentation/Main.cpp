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
			if(weg.getDistance() < 50)
			{
				int res=robert.grab();
				if(res != -1)
					break;
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
			if(weg.getDistance() < 50)
			{
				int resultaat = robert.drop();
				break;
				delete robert;
			}
		}
	}
	cout << "is het gepakt? " << res << endl;

	return 0;
}

