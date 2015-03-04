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
/*
*		constructor
*		toekenning + berekenen van score
*/
Vak::Vak(int x,int y,int angle, int dx, int dy, Vak* parent) {
		cout << "Calculating for:"<< endl;
		cout << "Vakje(" << x << "," << y <<")"<< endl;		
		this->x = x;
		this->y = y;
		cout << "hoek(" << angle*45 << "," << y <<")"<< endl;
		this->theta= angle;
		this->parent = parent;
		this->score =(abs((x-dx)+(y-dy)) + theta*THETAFACTOR );	
		cout << "score for:"<< endl;
		cout << "Vak created"<< endl;
}

void Vak::print() {
		cout << "Vakje(" << x << "," << y <<")"<< endl;		
		cout << "hoek(" << theta*45 << "," << y <<")"<< endl;	
		cout << "score for:"<< score << endl;
		cout << "Vak created"<< endl;
}