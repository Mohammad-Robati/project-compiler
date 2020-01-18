
#include <stdio.h>
#include <stdlib.h>

int main()
{

double first;
double num;
double sec;
double fibonacci;void* returnAddress;
double * top = (double*) malloc(1000 * sizeof(double));
void ** labelsTop = (void**) malloc(1000 * sizeof(void*));
top += 1000;
labelsTop += 1000;
double t0 ,t1;

goto _main;

_main:; //function decleration


 // function body:
num = 7;
// if statement
//new
if(num<3) goto L3;
goto L5;

L3: fibonacci = 1;
goto L4; //next label

L5: //else
first = 1;
sec = 1;
// FOR BEGIN

int i;
i = 1; // FOR initialization
L0: // for begin

t0 = num - 2;
if ( i <= t0 ) goto L1; // FOR check
goto L2;

L1: // for code begin
t1 = first + sec;
fibonacci = t1;
first = sec;
sec = fibonacci;
i = i + 1; // FOR iteration
goto L0; //back to for begin

L2: // end of for


L4:; //end of if statement - next
printf("%lf\n", fibonacci);

// function ended
goto end;



end : return 0;
}