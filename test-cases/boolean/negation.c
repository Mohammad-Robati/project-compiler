
#include <stdio.h>
#include <stdlib.h>

int main()
{

void* returnAddress;
double * top = (double*) malloc(1000 * sizeof(double));
void ** labelsTop = (void**) malloc(1000 * sizeof(void*));
top += 1000;
labelsTop += 1000;
double t0 ,t1 ,t2 ,t3;

goto _main;

_main:; //function decleration


 // function body:
int input;
int out;
input = 12201;
///////////////STORE REGS///////////////////
top = top - 1; // push { t0 }
*top = t0;

top = top - 1; // push { t1 }
*top = t1;

////////////////////////////////////////////

/////////////STORE VARIBLES///////////////
top = top - 1; // push { input }
*top = input;

top = top - 1; // push { out }
*top = out;

///////////////////////////////////////////

// store return label
labelsTop = labelsTop - 1; // push address{L1}
*labelsTop = &&L1;

// calc and store function arguments
///////////////STORE REGS///////////////////
top = top - 1; // push { t0 }
*top = t0;

////////////////////////////////////////////

/////////////STORE VARIBLES///////////////
top = top - 1; // push { input }
*top = input;

top = top - 1; // push { out }
*top = out;

///////////////////////////////////////////

// store return label
labelsTop = labelsTop - 1; // push address{L0}
*labelsTop = &&L0;

// calc and store function arguments
t0 = input + 2;

//--------STORE ARGS------------------
top = top - 1; // push { t0 }
*top = t0;


//----------------------------------------

// call function
goto neg;

// return label:
L0:;
// load return value
t1 = *top; // pop { t1 }
top = top + 1;

// load regs and vars

//^^^^^^^^^^^LOAD VARIBLES^^^^^^^^^^^^^^^^
out = *top; // pop { out }
top = top + 1;

input = *top; // pop { input }
top = top + 1;

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

//^^^^^^^^^^^^^LOAD REGS^^^^^^^^^^^^^^^^^^^
t0 = *top; // pop { t0 }
top = top + 1;

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

//--------STORE ARGS------------------
top = top - 1; // push { t1 }
*top = t1;


//----------------------------------------

// call function
goto neg;

// return label:
L1:;
// load return value
t2 = *top; // pop { t2 }
top = top + 1;

// load regs and vars

//^^^^^^^^^^^LOAD VARIBLES^^^^^^^^^^^^^^^^
out = *top; // pop { out }
top = top + 1;

input = *top; // pop { input }
top = top + 1;

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

//^^^^^^^^^^^^^LOAD REGS^^^^^^^^^^^^^^^^^^^
t1 = *top; // pop { t1 }
top = top + 1;

t0 = *top; // pop { t0 }
top = top + 1;

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
out = t2;

printf("%d\n", input);
		printf("%d\n", out);
// function ended
goto end;

neg:; //function decleration

// fetching arguments

input = *top; // pop { input }
top = top + 1;


 // function body:
// push return value to stack
t3 = -input;
top = top - 1; // push { t3 }
*top = t3;

returnAddress = *labelsTop; // pop return address
labelsTop = labelsTop + 1;

goto *returnAddress; // return from function


// function ended


end : return 0;
}