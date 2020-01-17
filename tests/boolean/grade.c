
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
double grade;
double _rating;
grade = 15;
// if statement
//new
if(grade>16) goto L8;
goto L11;

L8: _rating = 4;
goto L9; //next label

L11: //elseifs
if(grade>14) goto L5;
goto L7;

L5: //elseif epression
_rating = 3;
goto L9; // next label

L7: //elseif 
if(grade>12) goto L6;
goto L10;

L6: //elseif epression
_rating = 2;
goto L9; // next label


L10: //else
_rating = 1;

L9: //end of if statement - next
printf("%lf\n", _rating);

// function ended
goto end;



end : return 0;
}