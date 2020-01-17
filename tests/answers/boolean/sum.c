#include <stdio.h>

int main(){
	double number_;
	double ro_ot;
	double sumOdds;
	double odd;
	double T0;
	
	number_ = 100;
	ro_ot = 0;
	sumOdds = 0;
	odd = 0;
	
	L0:
		T0 = ro_ot * ro_ot;
		if(T0 <= number_) goto L1;
		goto L2;
		
		L1:
			if(odd) goto L3;
			goto L4;
			
			L3: sumOdds = sumOdds + ro_ot;
			
			L4: odd = 1 - odd;
			ro_ot = ro_ot + 1;
			
		goto L0;
			
		
	L2: printf("%lf\n", sumOdds);
	
	return 0;
}