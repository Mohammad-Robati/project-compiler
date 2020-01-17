#include <stdio.h>

int main(){
	double a, b, c, average;
	double T0, T1, T2;
	
	a = 4;
	b = 3;
	c = 1;
	
	T0 = a + b;
	T1 = T0 + c;
	T2 = T1 / 3;
	average = T2;
	
	printf("%lf\n", average);
	
	return 0;
}