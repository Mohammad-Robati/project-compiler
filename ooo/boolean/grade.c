
#include <stdio.h>
// Functions not yet 
void main()
{
double grade;
int _rating;
grade = 12;
// if
if(grade>16) goto L0;
goto L2;

L0: _rating = 4;
goto L1; //next label

L2: //else
_rating = 1;

L1: //end of if statement - next
}