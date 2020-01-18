
#include <stdio.h>
#include <stdlib.h>

int main()
{

double num;
double b;
double number1;
double number2;
double variance_;
double error_2;
double number4;
double error_1;
double error_5;
double error_3;
double a;
double number5;
double number3;
double average;
double error_4;
double d;
double c;void* returnAddress;
double * top = (double*) malloc(1000 * sizeof(double));
void ** labelsTop = (void**) malloc(1000 * sizeof(void*));
top += 1000;
labelsTop += 1000;
double t0 ,t1 ,t2 ,t3 ,t4 ,t5 ,t6 ,t7 ,t8 ,t9 ,t10 ,t11 ,t12 ,t13 ,t14 ,t15 ,t16 ,t17 ,t18 ,t19 ,t20 ,t21 ,t22 ,t23 ,t24 ,t25 ,t26 ,t27 ,t28;

goto _main;

_main:; //function decleration


 // function body:
number1 = 1;
number2 = 2;
number3 = 3;
number4 = 4;
number5 = 5;
t9 = number1 + number2;
t10 = t9 + number3;
t11 = t10 + number4;
t12 = t11 + number5;
t13 = t12 / 5;
average = t13;
t14 = number1 - average;
error_1 = t14;
t15 = number2 - average;
error_2 = t15;
t16 = number3 - average;
error_3 = t16;
t17 = number4 - average;
error_4 = t17;
t18 = number5 - average;
error_5 = t18;
t19 = error_1 * error_1;
t20 = error_2 * error_2;
t21 = t19 + t20;
t22 = error_3 * error_3;
t23 = t21 + t22;
t24 = error_4 * error_4;
t25 = t23 + t24;
t26 = error_5 * error_5;
t27 = t25 + t26;
t28 = t27 / 5;
variance_ = t28;
printf("%lf\n", variance_);

// function ended
goto end;



end : return 0;
}