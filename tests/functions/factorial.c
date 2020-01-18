
#include <stdio.h>
#include <stdlib.h>

int main()
{

double results;
double value;
double num;
double n;
double ret;void* returnAddress;
double * top = (double*) malloc(1000 * sizeof(double));
void ** labelsTop = (void**) malloc(1000 * sizeof(void*));
top += 1000;
labelsTop += 1000;
double t0 ,t1 ,t2 ,t3 ,t4;

num = 5;
goto _main;

factorial:; //function decleration

// fetching arguments

n = *top; // pop { n }
top = top + 1;


 // function body:
// if statement
//new
if(n<2) goto L0;
goto L1;

L0: // push return value to stack
top = top - 1; // push { 1 }
*top = 1;

returnAddress = *labelsTop; // pop return address
labelsTop = labelsTop + 1;

goto *returnAddress; // return from function

goto L1; //next label

L1:; //end of if statement - next
///////////////STORE REGS///////////////////
top = top - 1; // push { t0 }
*top = t0;

////////////////////////////////////////////

/////////////STORE VARIBLES///////////////
top = top - 1; // push { num }
*top = num;

top = top - 1; // push { n }
*top = n;

///////////////////////////////////////////

// store return label
labelsTop = labelsTop - 1; // push address{L2}
*labelsTop = &&L2;

// calc and store function arguments
t0 = n - 1;

//--------STORE ARGS------------------
top = top - 1; // push { t0 }
*top = t0;


//----------------------------------------

// call function
goto factorial;

// return label:
L2:;
// load return value
t1 = *top; // pop { t1 }
top = top + 1;

// load regs and vars

//^^^^^^^^^^^LOAD VARIBLES^^^^^^^^^^^^^^^^
n = *top; // pop { n }
top = top + 1;

num = *top; // pop { num }
top = top + 1;

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

//^^^^^^^^^^^^^LOAD REGS^^^^^^^^^^^^^^^^^^^
t0 = *top; // pop { t0 }
top = top + 1;

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
value = t1;
t2 = n * value;
ret = t2;
// push return value to stack
top = top - 1; // push { ret }
*top = ret;

returnAddress = *labelsTop; // pop return address
labelsTop = labelsTop + 1;

goto *returnAddress; // return from function


// function ended
_main:; //function decleration


 // function body:
///////////////STORE REGS///////////////////
top = top - 1; // push { t0 }
*top = t0;

top = top - 1; // push { t1 }
*top = t1;

top = top - 1; // push { t2 }
*top = t2;

top = top - 1; // push { t3 }
*top = t3;

////////////////////////////////////////////

/////////////STORE VARIBLES///////////////
top = top - 1; // push { num }
*top = num;

top = top - 1; // push { n }
*top = n;

top = top - 1; // push { value }
*top = value;

top = top - 1; // push { ret }
*top = ret;

///////////////////////////////////////////

// store return label
labelsTop = labelsTop - 1; // push address{L3}
*labelsTop = &&L3;

// calc and store function arguments
t3 = num + 2;

//--------STORE ARGS------------------
top = top - 1; // push { t3 }
*top = t3;


//----------------------------------------

// call function
goto factorial;

// return label:
L3:;
// load return value
t4 = *top; // pop { t4 }
top = top + 1;

// load regs and vars

//^^^^^^^^^^^LOAD VARIBLES^^^^^^^^^^^^^^^^
ret = *top; // pop { ret }
top = top + 1;

value = *top; // pop { value }
top = top + 1;

n = *top; // pop { n }
top = top + 1;

num = *top; // pop { num }
top = top + 1;

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

//^^^^^^^^^^^^^LOAD REGS^^^^^^^^^^^^^^^^^^^
t3 = *top; // pop { t3 }
top = top + 1;

t2 = *top; // pop { t2 }
top = top + 1;

t1 = *top; // pop { t1 }
top = top + 1;

t0 = *top; // pop { t0 }
top = top + 1;

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
results = t4;
printf("%lf\n", results);

// function ended
goto end;



end : return 0;
}