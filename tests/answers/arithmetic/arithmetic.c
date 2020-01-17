#include <stdio.h>

int main(){
	double a, b, c;
	double T0, T1, T2, T3, T4;
	
	a = 4;
	
	T0 = 3 % 2;
	T1 = a * T0;
	b = T1;
	
	T2 = b - 3;
	T3 = T2 * 2;
	T4 = 1.5 + T3;
	c = T4;
	
	printf("%lf\n", c);
	
	return 0;
}