#include "Vak.h"
#include <vector>
using namespace std;

#define FIELDX 10
#define FIELDY 15


int main () {
  vector<Vak> vakvector;
  Vak begin = Vak(1,1,0,5,5,NULL);
  Vak current = begin;
  vakvector.push_back(begin);
  begin.print();
  int found = 0;
 while(found == 0){
//while lus 
  int x = current.getx();
  int y = current.gety();
  int theta	= current.getTheta(); 
    
  //check vakje klopt?
  if(current.getScore() == 0){
	cout << "match!" << endl;
	found = 1;
	break;
  }
  
  //bepalen volgende vakjes
  //RB
  Vak next = Vak(x+1,y+1,1,5,5,&current);
  vakvector.push_back(next);
  //MB
  Vak next = Vak(x,y+1,2,5,5,&current);
  vakvector.push_back(next);
  //LB
  Vak next = Vak(x-1,y+1,1,5,5,&current);
  vakvector.push_back(next);
  //LM
  Vak next = Vak(x-1,y,0,5,5,&current);
  vakvector.push_back(next);
  //LO
  Vak next = Vak(x-1,y-1,1,5,5,&current);
  vakvector.push_back(next);
  //MO
  Vak next = Vak(x,y-1,2,5,5,&current);
  vakvector.push_back(next);
  //R0
  Vak next = Vak(x+1,y-1,1,5,5,&current);
  vakvector.push_back(next);
  //RM
  Vak next = Vak(x+1,y,0,5,5,&current);
  vakvector.push_back(next);
  
  //select next current
  std::vector<Vak>::iterator it;
  for (it=myvector.begin(); it<myvector.end(); it++){
	if(it.getScore() < current.getScore()){
			current = it;
	}
  }
  
	current.print();
}
	cout << "--Backtracking ---"<< endl;
	Vak loper = current;
	while(loper.getParent() != NULL)
	{
		loper.print();
		loper = loper.getParent();
		
	}

  return 0;
}

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