#include <iostream>

class Robo{
	int reqSpeed;
	
	public:
		Robo(int);
		int getDistanceSensor();
		bool grab();
		bool drop();
		void elMove(char);
		void move(int,int);}
