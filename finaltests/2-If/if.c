
#include <stdio.h>
#include <stdlib.h>

int main()
{

double n;void* returnAddress;
double * top = (double*) malloc(1000 * sizeof(double));
void ** labelsTop = (void**) malloc(1000 * sizeof(void*));
top += 1000;
labelsTop += 1000;

goto _main;

_main:; //function decleration


 // function body:
n = 24;
// if statement
//new
if(n>=24) goto L1;
goto L11;

L1: // logical calculation (AND)
L0: // logical calculation (OR)
L9: // if statement
//new
if(n==32) goto L5;
goto L8;

L5: n = 3;
goto L6; //next label

L8: //elseifs
if(n==44) goto L2;
goto L4;

L2: //elseif epression
n = 4;
goto L6; // next label

L4: //elseif 
if(n==60) goto L3;
goto L7;

L3: //elseif epression
n = 5;
goto L6; // next label


L7: //else
n = 6;

L6:; //end of if statement - next
goto L10; //next label

L11: //else
n = 0;

L10:; //end of if statement - next
printf("%lf\n", n);

// function ended
goto end;



end : return 0;
}