#include "Robo.h"
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include <wiringPi.h>
#include <wiringSerial.h>

#include <sys/socket.h>
#include <netinet/in.h>

#include <vector>

int fd;
Robo::Robo(int myReqSpeed){
	reqSpeed = myReqSpeed;
	if ((fd = serialOpen ("/dev/ttyUSB0", 38400)) < 0)
	{
    		fprintf (stderr, "Unable to open serial device: %s\n", strerror (errno)) ;
   		 return 1 ;
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

void move(int myAngle, int myDistance){
	int l = sin(myAngle) * reqSpeed;
	int r = cos(myAngle) * reqSpeed;
	char bufferL[3];
	char bufferR[3];
	
	itoa(l, bufferL, 10);
	itoa(r, bufferR, 10);
	
	serialPutchar(fd, 'q');
	serialPutchar(fd, ' ');
	for(int i = 0; i < 3; i++){
		//check voor eerste nullen anders break
	}	

}
