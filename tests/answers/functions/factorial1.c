#include <stdio.h>
#include <stdlib.h>

int main(){
	double num, n, value, results, T0, T1, T2, T3, T4;
	double* stackTop = malloc(10000);
	void** labelStackTop = malloc(10000);
	void* returnAddress;
	
	num = 2;
	
	goto _main;
	
	factorial:
		// Pop parameters.
		n = pop();
		
		if(n < 2) goto L1;
		goto L2;
		
		// Pop return address.
		L1: returnAddress = pop();
		// Push return value.
		push(1);
		// Return.
		goto returnAddress;
		
		// Store program state;
		L2: push(n);
		// Store return address.
		push(L3);
		// Push parameters.
		T2 = n - 1;
		push(T2);
		// Call function.
		goto factorial;
		// Return from factorial and pop the returned value.
		L3: T3 = pop();
		value = T3;
		// Restore program state.
		n = pop();
		
		T4 = n * value;
		// Pop return address.
		returnAddress = pop();
		// Push return value.
		push(T4);
		// Return.
		goto returnAddress;
	
	_main:
		// Store program state.
		/* Empty */
		
		// Store return address.
		push(L0);
		
		// Push parameters.
		T0 = num + 2;
		push(T0);
		
		// Call function.
		goto factorial;
		
		// Return from factorial and pop the returned value.
		L0: T1 = pop();
		results = T1;
		
		printf("%lf\n", results);
		
		// Terminate the program.
		goto end;
		
	end: return 0;
}