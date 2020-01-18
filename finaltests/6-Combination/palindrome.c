
#include <stdio.h>
#include <stdlib.h>

int main()
{

double q;
double units;
double num;
double pal;
double r;void* returnAddress;
double * top = (double*) malloc(1000 * sizeof(double));
void ** labelsTop = (void**) malloc(1000 * sizeof(void*));
top += 1000;
labelsTop += 1000;
double t0 ,t1 ,t2 ,t3 ,t4 ,t5 ,t6 ,t7 ,t8 ,t9 ,t10 ,t11;

goto _main;

_main:; //function decleration


 // function body:
num = 5523;
///////////////STORE REGS///////////////////
////////////////////////////////////////////

/////////////STORE VARIBLES///////////////
top = top - 1; // push { num }
*top = num;

///////////////////////////////////////////

// store return label
labelsTop = labelsTop - 1; // push address{L0}
*labelsTop = &&L0;

// calc and store function arguments

//--------STORE ARGS------------------
top = top - 1; // push { num }
*top = num;


//----------------------------------------

// call function
goto getPalindrome;

// return label:
L0:;
// load return value
t0 = *top; // pop { t0 }
top = top + 1;

// load regs and vars

//^^^^^^^^^^^LOAD VARIBLES^^^^^^^^^^^^^^^^
num = *top; // pop { num }
top = top + 1;

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

//^^^^^^^^^^^^^LOAD REGS^^^^^^^^^^^^^^^^^^^
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
num = t0;
printf("%lf\n", num);

// function ended
goto end;

getPalindrome:; //function decleration

// fetching arguments

num = *top; // pop { num }
top = top + 1;


 // function body:
pal = 0;
L2: // while begin

if(num>=1) goto L3;
goto L4;

L3: // while code begin
///////////////STORE REGS///////////////////
top = top - 1; // push { t0 }
*top = t0;

////////////////////////////////////////////

/////////////STORE VARIBLES///////////////
top = top - 1; // push { num }
*top = num;

top = top - 1; // push { num }
*top = num;

top = top - 1; // push { pal }
*top = pal;

///////////////////////////////////////////

// store return label
labelsTop = labelsTop - 1; // push address{L1}
*labelsTop = &&L1;

// calc and store function arguments

//--------STORE ARGS------------------
top = top - 1; // push { num }
*top = num;


//----------------------------------------

// call function
goto getUnit;

// return label:
L1:;
// load return value
t1 = *top; // pop { t1 }
top = top + 1;

// load regs and vars

//^^^^^^^^^^^LOAD VARIBLES^^^^^^^^^^^^^^^^
pal = *top; // pop { pal }
top = top + 1;

num = *top; // pop { num }
top = top + 1;

num = *top; // pop { num }
top = top + 1;

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

//^^^^^^^^^^^^^LOAD REGS^^^^^^^^^^^^^^^^^^^
t0 = *top; // pop { t0 }
top = top + 1;

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
units = t1;
t2 = pal * 10;
t3 = t2 + units;
pal = t3;
t4 = num - units;
t5 = t4 / 10;
num = t5;
goto L2; //back to while begin

L4: // end of while

// push return value to stack
top = top - 1; // push { pal }
*top = pal;

returnAddress = *labelsTop; // pop return address
labelsTop = labelsTop + 1;

goto *returnAddress; // return from function


// function ended
getUnit:; //function decleration

// fetching arguments

num = *top; // pop { num }
top = top + 1;


 // function body:
q = 0;
r = 0;
L5: // while begin

t6 = q * 10;
if(t6<num) goto L6;
goto L7;

L6: // while code begin
t7 = q + 1;
q = t7;
goto L5; //back to while begin

L7: // end of while

// if statement
//new
t8 = q * 10;
if(num==t8) goto L8;
goto L9;

L8: // push return value to stack
top = top - 1; // push { 0 }
*top = 0;

returnAddress = *labelsTop; // pop return address
labelsTop = labelsTop + 1;

goto *returnAddress; // return from function

goto L9; //next label

L9:; //end of if statement - next
t9 = q - 1;
q = t9;
// push return value to stack
t10 = q * 10;
t11 = num - t10;
top = top - 1; // push { t11 }
*top = t11;

returnAddress = *labelsTop; // pop return address
labelsTop = labelsTop + 1;

goto *returnAddress; // return from function


// function ended


end : return 0;
}