#include "Robodriver.h"
using namespace std;

Robodriver::Robodriver()
{
    fd = 0;
    printf("Launching my driver, just a sec. \n");
    for (int i = 0; i < 3; i++)
    {
        sleep(1);
        printf(".\n");
    }
    setup();
    printf("Let's do a power-on test, shall we? \n");
    execute(POWER, 0);
    

}

Robodriver::~Robodriver()
{
   printf("RIP in peace, driver. \n");
   char* stop = buildCommand(STOP);
   sendCommand(stop);
   sleep(1);
   serialClose(fd);
}

int Robodriver::execute(Action type, float distance)
{
    char* cmd = buildCommand(type);
    //moet misschien float zijn?
    float duration = 0.0;

    if ((type == 1) || (type == 2))
    {
        if(distance < 5)
		duration = 0;
	else
	{
		if(distance <0)
			distance *=-1.0;
		
		duration = distance/TURNRATE;
	}
    }
    else if ((type == 3) || (type == 4))
    {
        duration = abs(distance)/MOVERATE;
    }

    sendCommand(cmd);
//    cout << "sending command "<<cmd<<endl;
    cout << "with duration " << duration * 1000<<endl;
    
    usleep(duration*1000);
//    if(distance < 30)
  //  { 
    	char* stop = buildCommand(STOP);
    	printf("stopping this shit right here. \n");
    	sendCommand(stop);
    	delete[] stop;
   // }

    
    delete[] cmd;

    return 0;
}

char* Robodriver::buildCommand(Action type)
{
    cout<< "	We gaan een commando van type "<<type<< " bouwen"<<endl;
    char prefix = 'q';
    int lspeed, rspeed, grip;
    switch(type)
    {
        case 1:     prefix = 'q'; lspeed = -SPEED; rspeed = SPEED;      break; //links
        case 2:     prefix = 'q'; lspeed = SPEED; rspeed = -SPEED;      break; //rechts
        case 3:     prefix = 'q'; lspeed = SPEED; rspeed = SPEED;       break; //vooruit
        case 4:     prefix = 'q'; lspeed = -SPEED; rspeed = -SPEED;     break; //achteruit
        case 5:     prefix = 'g'; grip = '0';                           break; //open
        case 6:     prefix = 'g'; grip = '1';                           break; //dicht
        case 7:     prefix = 'u';                                       break; //distance sensor lezen
        case 8:     prefix = 't';                                       break; //power-on test
        case 0:     prefix = 'q'; lspeed = 0; rspeed = 0;               break; //stil (bij 0)
        default:    prefix = 'q'; lspeed = 0; rspeed = 0;               break; //stil
    }

    char* cmd = new char[CMDSIZE];

    string command;
    if (type <= 4)
    {
        command = "q " + toString(lspeed) + " " + toString(rspeed);
    }
    else if (type == 7)
    {
        command = "u";
    }
    else if (type == 8)
    {
        command = "t";
    }
	
    else
    {
	command == "g " + toString(grip);
    }

    cout << "	Dit zit er in command voor toevoeging:" << command <<endl;
    strncpy(cmd,command.c_str(),CMDSIZE-1);
    cout << "	Dit zit er in cmd voor toevoeging:" << cmd <<endl;
    cmd[command.size()] = 13;
    cmd[command.size()+1] = '\0';
    cout << "	Dit zit er in cmd na toevoeging:" << cmd <<endl;
    printf("	command length: %zd \n", strlen(cmd));
    return cmd;


}

int Robodriver::sendCommand(char* command)
{
    if (strlen(command) == 1)
    {
        const unsigned char singlechar = command[0];
        serialPutchar(fd, singlechar);
    }
    else if (strlen(command) > 1)
    {
	cout <<"			De robot gaat een command krijg" << endl;
        serialPuts(fd, command);
    }
    else
    {
        return -1;
    }
    cout << "sending command "<<command<<endl;

    return 0;
}

int Robodriver::setup()
{
    if ((fd = serialOpen(FILENAME,BAUDRATE)) < 0)
    {
         fprintf (stderr, "Unable to open serial device: %s\n", strerror (errno));
         return -1;
    }
    else
    {
        fprintf(stdout, "File-descriptor %d successfully opened. \n", fd);
    }

    return 0;
}

string Robodriver::toString(const int &number)
{
    stringstream ss;
    ss << number;
    return ss.str();
}
