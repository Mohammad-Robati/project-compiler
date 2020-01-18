
#include <stdio.h>
#include <stdlib.h>

int main()
{

double n;
double m;void* returnAddress;
double * top = (double*) malloc(1000 * sizeof(double));
void ** labelsTop = (void**) malloc(1000 * sizeof(void*));
top += 1000;
labelsTop += 1000;
double t0 ,t1 ,t2 ,t3 ,t4 ,t5;

goto _main;

_main:; //function decleration


 // function body:
n = 0;
// FOR BEGIN

int counter;
counter = 1; // FOR initialization
L21: // for begin

if ( counter <= 3 ) goto L22; // FOR check
goto L23;

L22: // for code begin
// FOR BEGIN

t2 = 3 - 2;
int i;
i = t2; // FOR initialization
L18: // for begin

t3 = 2 * 8;
if ( i <= t3 ) goto L19; // FOR check
goto L20;

L19: // for code begin
t4 = i * 3;
t5 = n + t4;
n = t5;
i = i + 2; // FOR iteration
goto L18; //back to for begin

L20: // end of for

counter = counter + 1; // FOR iteration
goto L21; //back to for begin

L23: // end of for

printf("%lf\n", n);

// function ended
goto end;



end : return 0;
}