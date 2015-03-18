#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <unistd.h>
#include "Client.h"
//#include "ObstacleData.h"

using namespace std;

/*RobotData *rob = new RobotData();
RobotData *robb = new RobotData();
vector<ObstacleData> *obstacles = new vector<ObstacleData>();
*/

void fillrobot(int gegevens[])
{

}

int main(int argc, char* argv[])
{
    Client *client;
    client = Client::getInstance();
    Info data;

    while(1){
        data = client->getData();
        /*
        cout<<"***** Ontvangen ******" << endl <<endl;
        cout<<"doel:"<<endl;
        cout<<"\tx: "<<data.doelx<<endl;
        cout<<"\ty: "<<data.doely<<endl;
        cout<<"garage:"<<endl;
        cout<<"\tx: "<<data.garx<<endl;
        cout<<"\ty: "<<data.gary<<endl;
        cout<<"robot:"<<endl;
        cout<<"\tx: "<<data.robx<<endl;
        cout<<"\ty: "<<data.roby<<endl;
        cout<<"\ta: "<<data.robhoek<<endl<<endl;
        */
    }
}
