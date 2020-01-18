
#include <stdio.h>
#include <stdlib.h>

int main()
{

double sum;
double b;
double a;void* returnAddress;
double * top = (double*) malloc(1000 * sizeof(double));
void ** labelsTop = (void**) malloc(1000 * sizeof(void*));
top += 1000;
labelsTop += 1000;
double t0 ,t1 ,t2 ,t3;

goto _main;

_main:; //function decleration


 // function body:
a = 33;
b = 72;
///////////////STORE REGS///////////////////
////////////////////////////////////////////

/////////////STORE VARIBLES///////////////
top = top - 1; // push { a }
*top = a;

top = top - 1; // push { b }
*top = b;

top = top - 1; // push { sum }
*top = sum;

///////////////////////////////////////////

// store return label
labelsTop = labelsTop - 1; // push address{L0}
*labelsTop = &&L0;

// calc and store function arguments

//--------STORE ARGS------------------
top = top - 1; // push { 72 }
*top = 72;

top = top - 1; // push { 33 }
*top = 33;


//----------------------------------------

// call function
goto add;

// return label:
L0:;
// load return value
t0 = *top; // pop { t0 }
top = top + 1;

// load regs and vars

//^^^^^^^^^^^LOAD VARIBLES^^^^^^^^^^^^^^^^
sum = *top; // pop { sum }
top = top + 1;

b = *top; // pop { b }
top = top + 1;

a = *top; // pop { a }
top = top + 1;

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

//^^^^^^^^^^^^^LOAD REGS^^^^^^^^^^^^^^^^^^^
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
sum = t0;
printf("%lf\n", sum);

// function ended
goto end;

add:; //function decleration

// fetching arguments

a = *top; // pop { a }
top = top + 1;

b = *top; // pop { b }
top = top + 1;


 // function body:
// if statement
//new
if(a==0) goto L1;
goto L2;

L1: // push return value to stack
top = top - 1; // push { b }
*top = b;

returnAddress = *labelsTop; // pop return address
labelsTop = labelsTop + 1;

goto *returnAddress; // return from function

goto L2; //next label

L2:; //end of if statement - next
// push return value to stack
///////////////STORE REGS///////////////////
top = top - 1; // push { t0 }
*top = t0;

top = top - 1; // push { t1 }
*top = t1;

////////////////////////////////////////////

/////////////STORE VARIBLES///////////////
top = top - 1; // push { a }
*top = a;

top = top - 1; // push { b }
*top = b;

top = top - 1; // push { sum }
*top = sum;

top = top - 1; // push { a }
*top = a;

top = top - 1; // push { b }
*top = b;

///////////////////////////////////////////

// store return label
labelsTop = labelsTop - 1; // push address{L3}
*labelsTop = &&L3;

// calc and store function arguments
t1 = a - 1;

//--------STORE ARGS------------------
top = top - 1; // push { b }
*top = b;

top = top - 1; // push { t1 }
*top = t1;


//----------------------------------------

// call function
goto add;

// return label:
L3:;
// load return value
t2 = *top; // pop { t2 }
top = top + 1;

// load regs and vars

//^^^^^^^^^^^LOAD VARIBLES^^^^^^^^^^^^^^^^
b = *top; // pop { b }
top = top + 1;

a = *top; // pop { a }
top = top + 1;

sum = *top; // pop { sum }
top = top + 1;

b = *top; // pop { b }
top = top + 1;

a = *top; // pop { a }
top = top + 1;

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

//^^^^^^^^^^^^^LOAD REGS^^^^^^^^^^^^^^^^^^^
t1 = *top; // pop { t1 }
top = top + 1;

t0 = *top; // pop { t0 }
top = top + 1;

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
t3 = t2 + 1;
top = top - 1; // push { t3 }
*top = t3;

returnAddress = *labelsTop; // pop return address
labelsTop = labelsTop + 1;

goto *returnAddress; // return from function


// function ended


end : return 0;
}