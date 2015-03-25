#include "Robo.h"


int reqSpeed;
Robo::Robo(){
}

void Robo::move(int myAngle, int myDistance){
	int l = (int) (sin(myAngle) * reqSpeed);
    int r = (int) cos(myAngle) * reqSpeed;

	///l omzetten naar een char array die per char aanspreekbaar is. wordt gestockeerd in bufferL
    stringstream strsl;
    strsl << l;
    string temp_strl = strsl.str();
    char* bufferL = (char*) temp_strl.c_str();

    ///r omzetten naar een char array die per char aanspreekbaar is. wordt gestockeerd in bufferR
    stringstream strsr;
    strsr << r;
    string temp_strr = strsr.str();
    char* bufferR = (char*) temp_strr.c_str();

    ///Naar de PI sturen dat we gaan beginnen
    serialPutchar(fd, 'q');
    serialPutchar(fd, ' ');

    ///overloop de waarde van bufferL char per char en stuur naar motor
    for(int i = 0; i<temp_strl.size(); i++)
    {

        cout << "Doorgestuurd character is: " << bufferL[i]<<endl;
    }

    ///Scheidingsteken linker en rechtermotor aandrijving
    serialPutchar(fd, ' ');

    ///overloop de waarde van bufferR char per char en stuur naar motor
    for(int i = 0; i<temp_strr.size(); i++)
    {
        serialPutchar(fd, bufferR[i]);
        cout << "Doorgestuurd character is:" << bufferR[i]<<endl;
    }

    /// Laat de robot rustig draaien (tijd dient aangepast te worden)
    sleep(3000);
}

