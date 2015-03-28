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
    printf("Let's do a power-on test, shall we? \n");
    execute(POWER, 0);

}

Robodriver::~Robodriver()
{
    printf("RIP in peace, driver. \n");
    serialClose(fd);
}

int Robodriver::execute(Action type, float distance)
{
    char* cmd = buildCommand(type);
    //moet misschien float zijn?
    int duration = 0;

    if ((type == 1) || (type == 2))
    {
        duration = abs(distance)/TURNRATE;
    }
    else if ((type == 3) || (type == 4))
    {
        duration = abs(distance)/MOVERATE;
    }

    sendCommand(cmd);
    printf("sending command \"%s\" with duration %d \n",cmd, duration);
    sleep(duration);
    char* stop = buildCommand(STOP);
    printf("stopping this shit right here. \n");
    sendCommand(stop);

    delete[] cmd;
    delete[] stop;

    return 0;
}

char* Robodriver::buildCommand(Action type)
{
    char prefix = 'q';
    int lspeed, rspeed, grip;
    switch(type)
    {
        case 1:     prefix = 'q'; lspeed = -SPEED; rspeed = SPEED;      break; //links
        case 2:     prefix = 'q'; lspeed = SPEED; rspeed = -SPEED;      break; //rechts
        case 3:     prefix = 'q'; lspeed = SPEED; rspeed = SPEED;       break; //vooruit
        case 4:     prefix = 'q'; lspeed = -SPEED; rspeed = -SPEED;     break; //achteruit
        case 5:     prefix = 'g'; grip = '1';                           break; //open
        case 6:     prefix = 'g'; grip = '0';                           break; //dicht
        case 7:     prefix = 'u';                                       break; //distance sensor lezen
        case 8:     prefix = 't';                                       break; //power-on test
        case 0:     prefix = 'q'; lspeed = 0; rspeed = 0;               break; //stil (bij 0)
        default:    prefix = 'q'; lspeed = 0; rspeed = 0;               break; //stil
    }

    char* cmd = new char[CMDSIZE];

    string command;
    if (type <= 4)
    {
        command = prefix + " " + toString(lspeed) + " " + toString(rspeed);
    }
    else if (type > 6)
    {
        command = prefix;
    }
    else
    {
        command = prefix + " " + grip;
    }
    strncpy(cmd,command.c_str(),command.size()-1);
    cmd[strlen(cmd)] = 13;
    cmd[strlen(cmd)+1] = '\0';

    printf("command length: %zd \n", strlen(cmd));
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
        serialPuts(fd, command);
    }
    else
    {
        return -1;
    }

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
