
#include <stdio.h>
#include <stdlib.h>

int main()
{

double num;
double found;
double q;
double counter;
double r;
double max;void* returnAddress;
double * top = (double*) malloc(1000 * sizeof(double));
void ** labelsTop = (void**) malloc(1000 * sizeof(void*));
top += 1000;
labelsTop += 1000;
double t0 ,t1 ,t2 ,t3 ,t4 ,t5;

goto _main;

_main:; //function decleration


 // function body:
counter = 0;
num = 2;
max = 10;
L10: // while begin

if(counter!=max) goto L11;
goto L12;

L11: // while code begin
found = 0;
// FOR BEGIN

int i;
i = 2; // FOR initialization
L5: // for begin

t0 = num - 1;
if ( i <= t0 ) goto L6; // FOR check
goto L7;

L6: // for code begin
q = 0;
r = 0;
L0: // while begin

t1 = q * i;
if(t1<num) goto L1;
goto L2;

L1: // while code begin
t2 = q + 1;
q = t2;
goto L0; //back to while begin

L2: // end of while

// if statement
//new
t3 = q * i;
if(num==t3) goto L3;
goto L4;

L3: i = num;
found = 1;
goto L4; //next label

L4:; //end of if statement - next
i = i + 1; // FOR iteration
goto L5; //back to for begin

L7: // end of for

// if statement
//new
if(found==0) goto L8;
goto L9;

L8: printf("%lf\n", num);
t4 = counter + 1;
counter = t4;
goto L9; //next label

L9:; //end of if statement - next
t5 = num + 1;
num = t5;
goto L10; //back to while begin

L12: // end of while


// function ended
goto end;



end : return 0;
}