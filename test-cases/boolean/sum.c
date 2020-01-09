
#include <stdio.h>
// Functions not yet 
void main()
{

double t0 ,t1 ,t2 ,t3;

int number_;
int ro_ot;
int sumOdds;
int odd;
number_ = 100;
ro_ot = 0;
sumOdds = 0;
odd = 0;
L2: // while begin

t0 = ro_ot * ro_ot;
if(t0<=number_) goto L3;
goto L4;

L3: // while code begin
// if statement
if ( odd != 0) goto L0;
goto L1;

L0: t1 = sumOdds + ro_ot;
sumOdds = t1;
goto L1; //next label

L1: //end of if statement - next
t2 = 1 - odd;
odd = t2;
t3 = ro_ot + 1;
ro_ot = t3;
goto L2; //back to while begin

L4: // end of while

NOT YET FUNCTION CALL;


}