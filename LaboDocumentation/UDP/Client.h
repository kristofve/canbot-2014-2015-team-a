/**
 * @file Client.h
 * @author Frans Stijn
 * @brief Defines the class 'Client', Which will setup the client.
 */
#ifndef Client_H
#define Client_H

#include <iostream>
#include <iomanip>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

//#include "thread.h"
#include "RobotData.h"
#include "ObstacleData.h"
#include "Point.h"
#include "Package.h"

#define       UDPPORT       3200
#define       INBUFLEN      2048

#define groepA "192.168.1.11"
#define groepB "192.168.1.13"

using namespace std;

/**
 * @brief Defines the class 'Client', Which will setup the client.
 */
class Client //: public Thread
{
        int sockfd,n;
        int sockGroepB;
        struct sockaddr_in servaddr_a;
        struct sockaddr_in servaddr_GroepB;

       static Client* instance;


    public:
		/**
		 * @brief Runfunction of thead
		 */
       void run();
		/**
		 * @brief Making of Singleton class of type Client.
		 *
		 * @return	pointer to the Singleton instance.
		 */
       static Client* getInstance();
		/**
		 * @brief transferring the received data
		 * @param	Pointer of type RobotData to ownRobot.
		 * @param 	Pointer of type RobotData to other team's Robot.
		 * @param 	Pointer of type vector<ObstacleData> to the obstacles
		 * @return	Boolean true if message received
		 */

        //bool receive(RobotData *robot, RobotData *robotb, vector<Point> obstacles);


    private:
        Client();
       int init();
       char inbuf[INBUFLEN];
       int lengte;

       int sock;
       struct sockaddr_in cliAddr;
       struct sockaddr_in servAddr;
       Udp_package udp_package;
       /**
		 * @brief Constructor of the class Client.
		 */

};

#endif	/* Client_H */
