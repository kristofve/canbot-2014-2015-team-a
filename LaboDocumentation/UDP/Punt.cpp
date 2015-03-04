#include "Punt.h"
#include <iostream>

Punt::Punt(void){}


Punt::Punt (int a, int b) {
  x = a;
  y = b;
}

bool Punt::isGelijk(Punt a){	
	if (a.getx()==this->getx() && a.gety()==this->gety())		
		return true;
	else
		return false;
}

