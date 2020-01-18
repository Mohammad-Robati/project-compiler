
#include <stdio.h>
#include <stdlib.h>

int main()
{

void* returnAddress;
double * top = (double*) malloc(1000 * sizeof(double));
void ** labelsTop = (void**) malloc(1000 * sizeof(void*));
top += 1000;
labelsTop += 1000;
double t0 ,t1 ,t2 ,t3 ,t4 ,t5 ,t6;

goto _main;

_main:; //function decleration


 // function body:
int comb_;
int n;
int r;
n = 7;
r = 2;
///////////////STORE REGS///////////////////
////////////////////////////////////////////

/////////////STORE VARIBLES///////////////
top = top - 1; // push { comb_ }
*top = comb_;

top = top - 1; // push { n }
*top = n;

top = top - 1; // push { r }
*top = r;

///////////////////////////////////////////

// store return label
labelsTop = labelsTop - 1; // push address{L0}
*labelsTop = &&L0;

// calc and store function arguments

//--------STORE ARGS------------------
top = top - 1; // push { r }
*top = r;

top = top - 1; // push { n }
*top = n;


//----------------------------------------

// call function
goto combination;

// return label:
L0:;
// load return value
t0 = *top; // pop { t0 }
top = top + 1;

// load regs and vars

//^^^^^^^^^^^LOAD VARIBLES^^^^^^^^^^^^^^^^
r = *top; // pop { r }
top = top + 1;

n = *top; // pop { n }
top = top + 1;

comb_ = *top; // pop { comb_ }
top = top + 1;

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

//^^^^^^^^^^^^^LOAD REGS^^^^^^^^^^^^^^^^^^^
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
comb_ = t0;

printf("%d\n", comb_);
printf("%d\n", n);
// function ended
goto end;

combination:; //function decleration

// fetching arguments

n = *top; // pop { n }
top = top + 1;

r = *top; // pop { r }
top = top + 1;


		printf("New call: %d %d\n", n, r);
 // function body:
// if statement
//new
if(r==0) goto L2;
goto L1;

L1: // logical calculation (OR)
if(r==n) goto L2;
goto L3;

L2: // push return value to stack
top = top - 1; // push { 1 }
*top = 1;

returnAddress = *labelsTop; // pop return address
labelsTop = labelsTop + 1;

goto *returnAddress; // return from function

goto L3; //next label

L3: //end of if statement - next
// push return value to stack
///////////////STORE REGS///////////////////
top = top - 1; // push { t0 }
*top = t0;

top = top - 1; // push { t1 }
*top = t1;

top = top - 1; // push { t2 }
*top = t2;

////////////////////////////////////////////

/////////////STORE VARIBLES///////////////
top = top - 1; // push { comb_ }
*top = comb_;

top = top - 1; // push { n }
*top = n;

top = top - 1; // push { r }
*top = r;

///////////////////////////////////////////

// store return label
labelsTop = labelsTop - 1; // push address{L4}
*labelsTop = &&L4;

// calc and store function arguments
t1 = n - 1;
t2 = r - 1;

//--------STORE ARGS------------------
top = top - 1; // push { t2 }
*top = t2;

top = top - 1; // push { t1 }
*top = t1;


//----------------------------------------

// call function
goto combination;

// return label:
L4:;
// load return value
t3 = *top; // pop { t3 }
top = top + 1;

// load regs and vars

//^^^^^^^^^^^LOAD VARIBLES^^^^^^^^^^^^^^^^
r = *top; // pop { r }
top = top + 1;

n = *top; // pop { n }
top = top + 1;

comb_ = *top; // pop { comb_ }
top = top + 1;

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

//^^^^^^^^^^^^^LOAD REGS^^^^^^^^^^^^^^^^^^^
t2 = *top; // pop { t2 }
top = top + 1;

t1 = *top; // pop { t1 }
top = top + 1;

t0 = *top; // pop { t0 }
top = top + 1;

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
///////////////STORE REGS///////////////////
top = top - 1; // push { t0 }
*top = t0;

top = top - 1; // push { t1 }
*top = t1;

top = top - 1; // push { t2 }
*top = t2;

top = top - 1; // push { t3 }
*top = t3;

top = top - 1; // push { t4 }
*top = t4;

////////////////////////////////////////////

/////////////STORE VARIBLES///////////////
top = top - 1; // push { comb_ }
*top = comb_;

top = top - 1; // push { n }
*top = n;

top = top - 1; // push { r }
*top = r;

///////////////////////////////////////////

// store return label
labelsTop = labelsTop - 1; // push address{L5}
*labelsTop = &&L5;

// calc and store function arguments
t4 = n - 1;

//--------STORE ARGS------------------
top = top - 1; // push { r }
*top = r;

top = top - 1; // push { t4 }
*top = t4;


//----------------------------------------

// call function
goto combination;

// return label:
L5:;
// load return value
t5 = *top; // pop { t5 }
top = top + 1;

// load regs and vars

//^^^^^^^^^^^LOAD VARIBLES^^^^^^^^^^^^^^^^
r = *top; // pop { r }
top = top + 1;

n = *top; // pop { n }
top = top + 1;

comb_ = *top; // pop { comb_ }
top = top + 1;

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

//^^^^^^^^^^^^^LOAD REGS^^^^^^^^^^^^^^^^^^^
t4 = *top; // pop { t4 }
top = top + 1;

t3 = *top; // pop { t3 }
top = top + 1;

t2 = *top; // pop { t2 }
top = top + 1;

t1 = *top; // pop { t1 }
top = top + 1;

t0 = *top; // pop { t0 }
top = top + 1;

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
t6 = t3 + t5;
top = top - 1; // push { t6 }
*top = t6;

returnAddress = *labelsTop; // pop return address
labelsTop = labelsTop + 1;

goto *returnAddress; // return from function


// function ended


end : return 0;
}