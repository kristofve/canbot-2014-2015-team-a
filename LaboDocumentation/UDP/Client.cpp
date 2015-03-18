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

    sockfd = socket(AF_INET, SOCK_DGRAM,0);
    bzero(&servaddr_a,sizeof(servaddr_a));

    servaddr_a.sin_family = AF_INET;
    servaddr_a.sin_addr.s_addr=htonl(INADDR_ANY);
    servaddr_a.sin_port=htons(UDPPORT);

    if (bind(sockfd, (struct sockaddr *) &servaddr_a, sizeof(servaddr_a)) == -1) {
                std::cerr << "Error binding UDP socket" << std::endl;
                return -1;
        }

    std::cout << "Server gestart" << std::endl;

    return 0;
}

Info Client::getData()
{
	socklen_t len;
	len = sizeof(clientaddr_a);

    lengte = recvfrom(sockfd, &udp_package, sizeof(struct Udp_package), 0, (struct sockaddr*)&clientaddr_a, &len);

    return udp_package.info_a;

    /*cout<<"ontvangen ["<< lengte << "]" << endl <<endl;
    cout<<"doel:"<<endl;
    cout<<"\tx: "<<udp_package.info_a.doelx<<endl;
    cout<<"\ty: "<<udp_package.info_a.doely<<endl;
    cout<<"garage:"<<endl;
    cout<<"\tx: "<<udp_package.info_a.garx<<endl;
    cout<<"\ty: "<<udp_package.info_a.gary<<endl;
    cout<<"robot:"<<endl;
    cout<<"\tx: "<<udp_package.info_a.robx<<endl;
    cout<<"\ty: "<<udp_package.info_a.roby<<endl;
    cout<<"\ta: "<<udp_package.info_a.robhoek<<endl<<endl;
    */

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



