/**
*	headerfile Vak.h
*	Sam Liekens
*	Declaratie van Vak object
*	prototype function 
*/
#include<iostream>
#include<cmath>
//bepaalt hoeveel draaien doorweegt in de score
#define THETAFACTOR 2
using namespace std;

class Vak{
		int x;
		int y;
		int theta;
		//berekende waarde f = g(theta) + h
		int score;
		Vak *parent;
public:
			Vak(int,int,int,int,int,Vak*);
			int getx() {return x;};
			int gety() {return y;};
			int getTheta() {return theta;};
			Vak*getParent() {return parent;};
			int getScore(){return score;};
			void print();
};
