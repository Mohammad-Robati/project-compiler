
#include <stdio.h>
#include <stdlib.h>

int main()
{

void* returnAddress;
double * top = (double*) malloc(1000 * sizeof(double));
void ** labelsTop = (void**) malloc(1000 * sizeof(void*));
top += 1000;
labelsTop += 1000;
double t0 ,t1 ,t2 ,t3 ,t4;

goto _main;

_main:; //function decleration


 // function body:
double a;
double b;
double c;
a = 4;
t0 = 3 % 2;
t1 = a * t0;
b = t1;
t2 = b - 3;
t3 = t2 * 2;
t4 = 1.5 + t3;
c = t4;
printf("%lf\n", c);

// function ended
goto end;



end : return 0;
}