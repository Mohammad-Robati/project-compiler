#include <stdio.h>
#include <stdlib.h>

int main(){
	double num, n, value, results, T0, T1, T2, T3, T4;
	double* stackTop = (double*) malloc(10000 * sizeof(double));
	void** labelStackTop = (void**) malloc(10000 * sizeof(void*));
	void* returnAddress;
	
	labelStackTop += 10000;
	stackTop += 10000;
	
	num = 5;
	
	goto _main;
	
	factorial:
		// Pop parameters.
		n = *stackTop;
		stackTop = stackTop + 1;
		
		if(n < 2) goto L1;
		goto L2;
		
		// Pop return address.
		L1: returnAddress = *labelStackTop;
		labelStackTop = labelStackTop + 1;
		// Push return value.
		stackTop = stackTop - 1;
		*stackTop = 1;
		// Return.
		goto *returnAddress;
		
		// Store program state;
		L2: stackTop = stackTop - 1;
		*stackTop = n;
		// Store return address.
		labelStackTop = labelStackTop - 1;
		*labelStackTop = &&L3;
		// Push parameters.
		T2 = n - 1;
		stackTop = stackTop - 1;
		*stackTop = T2;
		// Call function.
		goto factorial;
		// Return from factorial and pop the returned value.
		L3: T3 = *stackTop;
		stackTop = stackTop + 1;
		value = T3;
		// Restore program state.
		n = *stackTop;
		stackTop = stackTop + 1;
		
		T4 = n * value;
		// Pop return address.
		returnAddress = *labelStackTop;
		labelStackTop = labelStackTop + 1;
		// Push return value.
		stackTop = stackTop - 1;
		*stackTop = T4;
		// Return.
		goto *returnAddress;
	
	_main:
		// Store program state.
		/* Empty */
		
		// Store return address.
		labelStackTop = labelStackTop - 1;
		*labelStackTop = &&L0;
		
		// Push parameters.
		T0 = num + 2;
		stackTop = stackTop - 1;
		*stackTop = T0;
		
		// Call function.
		goto factorial;
		
		// Return from factorial and pop the returned value.
		L0: T1 = *stackTop;
		stackTop = stackTop + 1;
		results = T1;
		
		printf("%lf\n", results);
		
		// Terminate the program.
		goto end;
		
	end: return 0;
}