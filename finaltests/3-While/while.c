
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
double t0 ,t1;

goto _main;

_main:; //function decleration


 // function body:
n = 5;
L15: // while begin

if(n>0) goto L16;
goto L17;

L16: // while code begin
m = n;
L12: // while begin

if(m>0) goto L13;
goto L14;

L13: // while code begin
printf("%lf\n", m);
t0 = m - 1;
m = t0;
goto L12; //back to while begin

L14: // end of while

t1 = n - 1;
n = t1;
goto L15; //back to while begin

L17: // end of while


// function ended
goto end;



end : return 0;
}