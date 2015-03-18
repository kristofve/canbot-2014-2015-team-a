#include "Robo.h"
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#include "wiringPi.h"
#include "wiringSerial.h"

#include <sys/socket.h>
#include <netinet/in.h>

#include <vector>
#include <sstream>

int fd;
int reqSpeed;
Robo::Robo(int myReqSpeed){
        reqSpeed = myReqSpeed;
        if ((fd = serialOpen ("/dev/ttyUSB0", 38400)) < 0)
        {
                fprintf (stderr, "Unable to open serial device: %s\n", strerror (errno)) ;
        }
}

int Robo::getDistanceSensor(){
        return 0;
}

bool grab(){
        serialPutchar(fd, 'g');
        serialPutchar(fd, ' ');
        serialPutchar(fd, '0');
        serialPutchar(fd, 13);
        return true;
}

bool drop(){
        serialPutchar(fd, 'g');
        serialPutchar(fd, ' ');
        serialPutchar(fd, '1');
        serialPutchar(fd, 13);  
        return true;
}

void elMove(char myChar){
       
}

void Robo::move(int myAngle, int myDistance){
        int l = (int) (sin(myAngle) * reqSpeed);
        int r = cos(myAngle) * reqSpeed;
        char bufferL[3];
        char bufferR[3];
       
	std::stringstream out;
	out << l;
	const char* templ = out.str().c_str();
	strncpy ( bufferL, templ, 3 );
        //itoa(l, bufferL, 10);
        //itoa(r, bufferR, 10);
	std::stringstream out2;
	out2 << r;
	const char* tempr = out2.str().c_str();
	strncpy ( bufferR, tempr, 3 );
       
        serialPutchar(fd, 'q');
        serialPutchar(fd, ' ');
        int lSpeedLoop = 2;
        for(int i = 0; i < 3; i++){
                //check voor eerste nullen anders break
                if(isdigit(bufferL[2-i])){
                        if(bufferL[2-i] != 0){
                                break;
                        }
                }
                lSpeedLoop--;
        }
        for(int j = lSpeedLoop; j > 0; j--){
                serialPutchar(fd, bufferL[j]);
        }      
        serialPutchar(fd, ' ');
        int rSpeedLoop = 2;
        for(int i = 0; i < 3; i++){
                //check voor eerste nullen anders break
                if(isdigit(bufferR[2-i])){
                        if(bufferR[2-i] != 0){
                                break;
                        }
                }
                rSpeedLoop--;
        }
        for(int j = rSpeedLoop; j > 0; j--){
                serialPutchar(fd, bufferR[j]);
        }      
        delay(3000);
        serialPutchar(fd, 'q');
        serialPutchar(fd, ' ');

}

