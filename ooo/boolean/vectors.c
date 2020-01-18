
#include <stdio.h>
#include <stdlib.h>

int main()
{

double * top = (double*) malloc(1000 * sizeof(double));
void ** labelsTop = (void**) malloc(1000 * sizeof(void*));
top += 1000;
labelsTop += 1000;
double t0 ,t1 ,t2 ,t3 ,t4 ,t5 ,t6 ,t7;

goto _main;

_main:; //function decleration

// pop arguments


 // function body:
double sum;
double something;
double length1;
double length2;
sum = 0;
length1 = 0;
// FOR BEGIN

int i;
i = 0; // FOR initialization
L3: // for begin

if ( i < 8 ) goto L4; // FOR check
goto L5;

L4: // for code begin
t0 = i * i;
t1 = length1 + t0;
length1 = t1;
length2 = 0;
// FOR BEGIN

int j;
j = 0; // FOR initialization
L0: // for begin

if ( j < 4 ) goto L1; // FOR check
goto L2;

L1: // for code begin
t2 = j * j;
t3 = length2 + t2;
length2 = t3;
t4 = i * j;
t5 = sum + t4;
sum = t5;
j = j + 1; // FOR iteration
goto L0; //back to for begin

L2: // end of for

i = i + 2; // FOR iteration
goto L3; //back to for begin

L5: // end of for

t6 = length1 * length2;
t7 = sum / t6;
something = t7;

// return from function
goto end;



end : return 0;
}