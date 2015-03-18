#include <iostream>
#ifndef _H_ROBO
#define _H_ROBO
class Robo{
        int reqSpeed;
       
        public:
                Robo(int);
                int getDistanceSensor();
                bool grab();
                bool drop();
                void elMove(char);
                void move(int,int);};


#endif
