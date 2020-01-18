
#include <stdio.h>
#include <stdlib.h>

int main()
{

double average;
double grade;
double length1;
double length2;
double a;
double something;
double number_;
double b;
double odd;
double sum;
double c;
double _rating;
double ro_ot;
double sumOdds;void* returnAddress;
double * top = (double*) malloc(1000 * sizeof(double));
void ** labelsTop = (void**) malloc(1000 * sizeof(void*));
top += 1000;
labelsTop += 1000;
double t0 ,t1 ,t2 ,t3 ,t4 ,t5 ,t6 ,t7 ,t8 ,t9 ,t10 ,t11 ,t12 ,t13 ,t14 ,t15 ,t16 ,t17 ,t18 ,t19;

goto _main;

_main:; //function decleration


 // function body:
sum = 0;
length1 = 0;
// FOR BEGIN

int i;
i = 0; // FOR initialization
L15: // for begin

if ( i < 8 ) goto L16; // FOR check
goto L17;

L16: // for code begin
t12 = i * i;
t13 = length1 + t12;
length1 = t13;
length2 = 0;
// FOR BEGIN

int j;
j = 0; // FOR initialization
L12: // for begin

if ( j < 4 ) goto L13; // FOR check
goto L14;

L13: // for code begin
t14 = j * j;
t15 = length2 + t14;
length2 = t15;
t16 = i * j;
t17 = sum + t16;
sum = t17;
j = j + 1; // FOR iteration
goto L12; //back to for begin

L14: // end of for

i = i + 2; // FOR iteration
goto L15; //back to for begin

L17: // end of for

t18 = length1 * length2;
t19 = sum / t18;
something = t19;
printf("%lf\n", something);

// function ended
goto end;



end : return 0;
}