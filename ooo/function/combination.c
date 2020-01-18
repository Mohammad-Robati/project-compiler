#include <stdio.h>
#include <stdlib.h>

int main(){
	double n, r, comb_;
	double T0, T1, T2, T3, T4, T5, T6, T7;
	void* returnAddress;
	
	double* top = (double*) malloc(1000 * sizeof(double));
	void** labelsTop = (void**) malloc(1000 * sizeof(void*));
	
	top += 1000;
	labelsTop += 1000;

	goto _main;
	
	_main:
		n = 7;
		r = 2;
		
		// Store Program State
		top = top - 1;
		*top = n;
		
		top = top - 1;
		*top = r;
		// -------------------
		
		// Return Label
		labelsTop = labelsTop - 1;
		*labelsTop = &&L0;
		
		// Parameters
		top = top - 1;
		*top = n;
		
		top = top - 1;
		*top = r;
		// ----------
		
		goto combination;
		
		L0: T0 = *top;
		top = top + 1;
		
		// Restore Program State
		r = *top;
		top = top + 1;
		
		n = *top;
		top = top + 1;
		// ---------------------
		
		comb_ = T0;

		printf("%lf\n", comb_);
		printf("%lf\n", n);
		goto end;
	
	combination:
		r = *top;
		top = top + 1;
		
		n = *top;
		top = top + 1;
		
		printf("New call: %lf %lf\n", n, r);
		
		if(r == 0) goto L1;
		goto L2;
		L2: if(r == n) goto L1;
		goto L3;
		
		L1:
			returnAddress = *labelsTop;
			labelsTop = labelsTop + 1;
			
			top = top - 1;
			*top = 1;
			
			goto *returnAddress;
		
		L3:
			top = top - 1;
			*top = n;
			
			top = top - 1;
			*top = r;
			
			labelsTop = labelsTop - 1;
			*labelsTop = &&L4;
			
			T1 = n - 1;
			top = top - 1;
			*top = T1;
			
			T2 = r - 1;
			top = top - 1;
			*top = T2;
			
			goto combination;
			
			L4: T3 = *top;
			top = top + 1;
			
			r = *top;
			top = top + 1;
			
			n = *top;
			top = top + 1;
			
			// Call the next combination.
			// Store Program State
			top = top - 1;
			*top = n;
			
			top = top - 1;
			*top = r;
			
			top = top - 1;
			*top = T3;
			// -------------------
			
			labelsTop = labelsTop - 1;
			*labelsTop = &&L5;
			
			T4 = n - 1;
			top = top - 1;
			*top = T4;
			
			T5 = r;
			top = top - 1;
			*top = T5;
			
			goto combination;
			
			L5: T6 = *top;
			top = top + 1;
			
			// Restore Program State
			T3 = *top;
			top = top + 1;
			
			r = *top;
			top = top + 1;
			
			n = *top;
			top = top + 1;
			// ---------------------
			
			// Return
			returnAddress = *labelsTop;
			labelsTop = labelsTop + 1;
			
			T7 = T3 + T6;
			
			top = top - 1;
			*top = T7;
			
			goto *returnAddress;

	end:
	
	return 0;
}