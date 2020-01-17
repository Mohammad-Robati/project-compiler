#include <stdio.h>

int main(){
	double sum;
	double something;
	double length1;
	double length2;
	
	double T0, T1, T2, T3;
	double i, j;
	
	sum = 0;
	
	length1 = 0;
	
	i = 0;
	L0:
		T0 = i * i;
		length1 = length1 + T0;
		
		length2 = 0;
		
		j = 0;
		L1:
			T1 = j * j;
			length2 = length2 + T1;
			
			T2 = i * j;
			sum = sum + T2;
			
			j = j + 1;
			if(j < 4) goto L1;
			goto L2;
		
		L2: i = i + 2;
		
		if(i < 8) goto L0;
		goto L3;
	
	L3: T3 = length1 * length2;
	something = sum / T3;
	
	printf("%lf\n", length1);
	printf("%lf\n", length2);
	printf("%lf\n", sum);
	printf("%lf\n", something);
	
	return 0;
}