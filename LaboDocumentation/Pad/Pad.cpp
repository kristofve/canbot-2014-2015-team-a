#include "Pad.h"
using namespace std;

#define FIELDX 10
#define FIELDY 15

int main () {
  Pad pad;
  pad.calc(0,0,3,1,1);
  
  
	for(int i = 0; i < FIELDX; i++){
		cout << "rij: " << i << ": ";
		for(int j = 0; j<FIELDY; j++){
			cout << " "<< j <<" ";
		}
		cout << endl;
	}
  return 0;
}

