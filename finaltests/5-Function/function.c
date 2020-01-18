
#include <stdio.h>
#include <stdlib.h>

int main()
{

double c;
double b;
double a;
double n;void* returnAddress;
double * top = (double*) malloc(1000 * sizeof(double));
void ** labelsTop = (void**) malloc(1000 * sizeof(void*));
top += 1000;
labelsTop += 1000;
double t0 ,t1 ,t2;

goto _main;

_main:; //function decleration


 // function body:
///////////////STORE REGS///////////////////
top = top - 1; // push { t0 }
*top = t0;

////////////////////////////////////////////

/////////////STORE VARIBLES///////////////
top = top - 1; // push { n }
*top = n;

///////////////////////////////////////////

// store return label
labelsTop = labelsTop - 1; // push address{L1}
*labelsTop = &&L1;

// calc and store function arguments
///////////////STORE REGS///////////////////
////////////////////////////////////////////

/////////////STORE VARIBLES///////////////
top = top - 1; // push { n }
*top = n;

///////////////////////////////////////////

// store return label
labelsTop = labelsTop - 1; // push address{L0}
*labelsTop = &&L0;

// calc and store function arguments

//--------STORE ARGS------------------
top = top - 1; // push { 3 }
*top = 3;

top = top - 1; // push { 2 }
*top = 2;

top = top - 1; // push { 1 }
*top = 1;


//----------------------------------------

// call function
goto f_2;

// return label:
L0:;
// load return value
t0 = *top; // pop { t0 }
top = top + 1;

// load regs and vars

//^^^^^^^^^^^LOAD VARIBLES^^^^^^^^^^^^^^^^
n = *top; // pop { n }
top = top + 1;

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

//^^^^^^^^^^^^^LOAD REGS^^^^^^^^^^^^^^^^^^^
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

//--------STORE ARGS------------------
top = top - 1; // push { 4 }
*top = 4;

top = top - 1; // push { t0 }
*top = t0;


//----------------------------------------

// call function
goto f_1;

// return label:
L1:;
// load return value
t1 = *top; // pop { t1 }
top = top + 1;

// load regs and vars

//^^^^^^^^^^^LOAD VARIBLES^^^^^^^^^^^^^^^^
n = *top; // pop { n }
top = top + 1;

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

//^^^^^^^^^^^^^LOAD REGS^^^^^^^^^^^^^^^^^^^
t0 = *top; // pop { t0 }
top = top + 1;

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
n = t1;
///////////////STORE REGS///////////////////
top = top - 1; // push { t0 }
*top = t0;

top = top - 1; // push { t1 }
*top = t1;

////////////////////////////////////////////

/////////////STORE VARIBLES///////////////
top = top - 1; // push { n }
*top = n;

///////////////////////////////////////////

// store return label
labelsTop = labelsTop - 1; // push address{L2}
*labelsTop = &&L2;

// calc and store function arguments

//--------STORE ARGS------------------

//----------------------------------------

// call function
goto f_3;

// return label:
L2:;
// load return value
t2 = *top; // pop { t2 }
top = top + 1;

// load regs and vars

//^^^^^^^^^^^LOAD VARIBLES^^^^^^^^^^^^^^^^
n = *top; // pop { n }
top = top + 1;

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

//^^^^^^^^^^^^^LOAD REGS^^^^^^^^^^^^^^^^^^^
t1 = *top; // pop { t1 }
top = top + 1;

t0 = *top; // pop { t0 }
top = top + 1;

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
n = t2;
printf("%lf\n", n);

// function ended
goto end;

f_1:; //function decleration

// fetching arguments

a = *top; // pop { a }
top = top + 1;

b = *top; // pop { b }
top = top + 1;


 // function body:
printf("%lf\n", a);
printf("%lf\n", b);
// push return value to stack
top = top - 1; // push { 0 }
*top = 0;

returnAddress = *labelsTop; // pop return address
labelsTop = labelsTop + 1;

goto *returnAddress; // return from function


// function ended
f_2:; //function decleration

// fetching arguments

a = *top; // pop { a }
top = top + 1;

b = *top; // pop { b }
top = top + 1;

c = *top; // pop { c }
top = top + 1;


 // function body:
printf("%lf\n", c);
// push return value to stack
top = top - 1; // push { 0 }
*top = 0;

returnAddress = *labelsTop; // pop return address
labelsTop = labelsTop + 1;

goto *returnAddress; // return from function


// function ended
f_3:; //function decleration


 // function body:
printf("%lf\n", 2.3);
// push return value to stack
top = top - 1; // push { 0 }
*top = 0;

returnAddress = *labelsTop; // pop return address
labelsTop = labelsTop + 1;

goto *returnAddress; // return from function


// function ended


end : return 0;
}