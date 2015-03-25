#include <iostream>
#ifndef _H_ROBO
#define _H_ROBO
using namespace std;
class Robo{
        int reqSpeed;
       
        public:
		Robo();	
                Robo(int);
                int getDistanceSensor();
                bool grab();
                bool drop();
                void elMove(char);
                void move(int,int);};


#endif
