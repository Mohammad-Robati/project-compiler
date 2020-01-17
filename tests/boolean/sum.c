
#include <stdio.h>
#include <stdlib.h>

int main()
{

void* returnAddress;
double * top = (double*) malloc(1000 * sizeof(double));
void ** labelsTop = (void**) malloc(1000 * sizeof(void*));
top += 1000;
labelsTop += 1000;
double t0 ,t1 ,t2 ,t3 ,t4 ,t5 ,t6 ,t7 ,t8 ,t9 ,t10 ,t11;

goto _main;

_main:; //function decleration


 // function body:
double number_;
double ro_ot;
double sumOdds;
double odd;
number_ = 100;
ro_ot = 0;
sumOdds = 0;
odd = 0;
L2: // while begin

t8 = ro_ot * ro_ot;
if(t8<=number_) goto L3;
goto L4;

L3: // while code begin
// if statement
//new
if ( odd != 0) goto L0;
goto L1;

L0: t9 = sumOdds + ro_ot;
sumOdds = t9;
goto L1; //next label

L1: //end of if statement - next
t10 = 1 - odd;
odd = t10;
t11 = ro_ot + 1;
ro_ot = t11;
goto L2; //back to while begin

L4: // end of while

printf("%lf\n", sumOdds);

// function ended
goto end;



end : return 0;
}