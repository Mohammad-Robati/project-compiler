#include <stdio.h>
#include <stdlib.h>

int main(){
	double input, out;
	double T0, T1, T2;
	void* returnAddress;
	
	double* top = (double*) malloc(1000 * sizeof(double));
	void** labelsTop = (void**) malloc(1000 * sizeof(void*));
	
	top += 1000;
	labelsTop += 1000;

	goto _main;
	
	_main:
		input = 12201;
		
		T0 = input + 2;
		
		// Store Program State
		top = top - 1;
		*top = input;
		
		// Store Return Label
		labelsTop = labelsTop - 1;
		*labelsTop = &&L0;
		
		// Push Parameters
		top = top - 1;
		*top = T0;
		
		// Call Function
		goto neg;
		
		// Retrieve Return Value
		L0: T1 = *top;
		top = top + 1;
		
		// Restore Program State
		input = *top;
		top = top + 1;
		
		// Call Outer Function
		// Store Program State
		top = top - 1;
		*top = input;
		
		// Store Return Label
		labelsTop = labelsTop - 1;
		*labelsTop = &&L1;
		
		// Push Parameters
		top = top - 1;
		*top = T1;
		
		// Call Function
		goto neg;
		
		// Retrieve Return Value
		L1: T1 = *top;
		top = top + 1;
		
		// Restore Program State
		input = *top;
		top = top + 1;
		
		out = T1;
		
		printf("%lf\n", input);
		printf("%lf\n", out);

		goto end;

	neg:
		// Pop Parameters
		input = *top;
		top = top + 1;
		
		T2 = -input;
		
		// Pop Return Address
		returnAddress = *labelsTop;
		labelsTop = labelsTop + 1;
		
		// Push Return Value
		top = top - 1;
		*top = T2;
		
		// Return
		goto *returnAddress;
		
	end:
	
	return 0;
}