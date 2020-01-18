
#include <stdio.h>
#include <stdlib.h>

int main()
{

double b;
double average;
double a;
double c;void* returnAddress;
double * top = (double*) malloc(1000 * sizeof(double));
void ** labelsTop = (void**) malloc(1000 * sizeof(void*));
top += 1000;
labelsTop += 1000;
double t0 ,t1 ,t2 ,t3 ,t4 ,t5 ,t6 ,t7;

goto _main;

_main:; //function decleration


 // function body:
a = 4;
b = 3;
c = 1;
t5 = a + b;
t6 = t5 + c;
t7 = t6 / 3;
average = t7;
printf("%lf\n", average);

// function ended
goto end;



end : return 0;
}