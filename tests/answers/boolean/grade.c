#include <stdio.h>

int main(){
	double grade, _rating;
	
	grade = 15;
	
	if(grade > 16) goto L1;
	goto L2;
	
	L1: _rating = 4;
	goto L0;
	
	L2: if(grade > 14) goto L3;
	goto L4;
	
	L3: _rating = 3;
	goto L0;
	
	L4: if(grade > 12) goto L5;
	goto L6;
	
	L5: _rating = 2;
	goto L0;
	
	L6: _rating = 1;
	
	
	L0: printf("%lf\n", _rating);
	
	return 0;
}