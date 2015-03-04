
	#include <iostream>
#pragma once
class Punt {
    int x, y;
  public:
	  Punt(void);
    Punt (int,int);
    int getx () {return x;}
	int gety () {return y;}
	bool isGelijk(Punt);
	void printPunt(){std::cout<<"x: "<<getx()<<"\ty: "<<gety()<<"\n";}
};