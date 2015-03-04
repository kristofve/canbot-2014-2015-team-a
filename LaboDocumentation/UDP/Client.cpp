/**
 * @file Client.cpp
 * @author Frans Stijn
 * @brief Defines the functions declared in Client.h.
 */
#include "Client.h"
#include <unistd.h>

Client* Client::instance = NULL;

Client* Client::getInstance()
{
    if(instance == NULL)
    {
        instance = new Client();
        //cout << "instance gemaakt" << endl;
    }
    return instance;
}

Client::Client()
{
	if(init() == -1)
	{
	cout << "init failed" << endl;
        exit(1);
	}
}

int Client::init()
{

    sockfd = socket(AF_INET,SOCK_DGRAM,0);
    bzero(&servaddr_a,sizeof(servaddr_a));

    servaddr_a.sin_family = AF_INET;
    servaddr_a.sin_addr.s_addr=INADDR_ANY;
    servaddr_a.sin_port=htons(UDPPORT);

    return 0;
}

void Client::run()
{
	socklen_t len;
	len = sizeof(servaddr_a);

    while(1)
    {
        lengte = recvfrom(sockfd, &udp_package, sizeof(struct Udp_package), 0, (struct sockaddr*)&servaddr_a, &len);
        cout<<"ontvangen ["<< lengte << "]" << endl;
        cout<<"\t"<<udp_package.groep_a<<endl;
    }
    close(sockfd);
}
/*
bool Client::receive()
{
    if(lengte!=0)
    {
        robotinfo robfo;
        int aantobs;

        memcpy((void*)&robfo, inbuf, sizeof(robotinfo));
        robot->set_robot(robfo.ax,robfo.ay,robfo.aa);
        robot->set_blikje(robfo.axc, robfo.ayc);
        robot->set_garage(robfo.axg, robfo.ayg);

        robotb->set_robot(robfo.bx,robfo.by,robfo.ba);
        robotb->set_blikje(robfo.bxc, robfo.byc);
        robotb->set_garage(robfo.bxg, robfo.byg);
        aantobs=(lengte-64)/4;


        if (! obstacles.empty())
            obstacles.clear();


        for(int i=0;i<(aantobs/2);i++)
        {
        Point blik(robfo.obs[0+(2*i)],robfo.obs[1+(2*i)]);
        obstacles.push_back(blik);

        }
        //	cout << "ik kom hier" << endl;
        lengte=0;
        return true;
    }
    else
    {
        return false;
    }
}*/



