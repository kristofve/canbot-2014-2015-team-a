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
       static Client* instance;

    public:
       void run();
       static Client* getInstance();

    private:
       Client();
       int init();
       int lengte;

       int sockfd,n;
       struct sockaddr_in servaddr_a;
       struct sockaddr_in clientaddr_a;

       Udp_package udp_package;
};

#endif	/* Client_H */
