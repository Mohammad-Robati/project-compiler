
#include <stdio.h>
#include <stdlib.h>

int main()
{

double num;
double b;
double a;
double d;
double c;void* returnAddress;
double * top = (double*) malloc(1000 * sizeof(double));
void ** labelsTop = (void**) malloc(1000 * sizeof(void*));
top += 1000;
labelsTop += 1000;
double t0 ,t1 ,t2 ,t3 ,t4 ,t5 ,t6 ,t7 ,t8;

goto _main;

_main:; //function decleration


 // function body:
num = 3;
a = 1;
b = 2;
c = 3;
d = 4;
t0 = num * num;
t1 = -t0;
t2 = 1 / a;
t3 = 1 / b;
t4 = t2 + t3;
t5 = 1 / c;
t6 = t4 + t5;
t7 = t6 * d;
t8 = t1 - t7;
num = t8;
printf("%lf\n", num);

// function ended
goto end;



end : return 0;
}