from register import Register

TRUE_LABEL = "TRUE_LABEL"
FALSE_LABEL = "FALSE_LABEL"
NEXT_LABEL = "NEXT_LABEL"
VARIABLES = []

def binary_operation_code(p):
    reg = Register('double')

    p[0].place = reg.place
    p[0].code = p[1].code + p[3].code +  p[0].place + " = " + p[1].get_value() + " " + p[2] + " " + p[3].get_value() + ";\n"

def unary_operation_code(p):
    reg = Register('double')
    p[0].place = reg.place
    p[0].code = p[2].code +  p[0].place + " = " + p[1] + p[2].get_value() + ";\n"
    print("...**__", id(p[0]))

def comparison_operation_code(p):
    p[0].code = p[1].code + p[3].code + "if(" + p[1].get_value() + p[2] + p[3].get_value() + ") goto " + TRUE_LABEL + ";\n" + "goto " + FALSE_LABEL + ";\n\n"

def back_patch_true(exp, true_label):
    exp.code = exp.code.replace(TRUE_LABEL, true_label.label)

def back_patch_false(exp, false_label):
    exp.code = exp.code.replace(FALSE_LABEL, false_label.label)

def back_patch_next(exp, next_label):
    exp.code = exp.code.replace(NEXT_LABEL, next_label.label)

def push_variable(variable):
    code = "top = top - 1; // push { " + variable + " }\n"
    code += "*top = " + variable + ";\n\n"
    return code

def pop_variable(variable):
    code = variable + " = *top; // pop { " + variable + " }\n"  
    code += "top = top + 1;\n\n"
    return code

def push_address(label):
    code = "labelsTop = labelsTop - 1; // push address{" + label + "}\n"
    code += "*labelsTop = &&" + label + ";\n\n"
    return code

def pop_return_address():
    code = "returnAddress = *labelsTop; // pop return address\n"
    code += "labelsTop = labelsTop + 1;\n\n"
    return code

def return_code():
    code = "goto *returnAddress; // return from function\n\n"
    return code

def store_all_registers(registers):
    code = "///////////////STORE REGS///////////////////\n"
    for register in registers:
        code += push_variable(register.place)
    code += "////////////////////////////////////////////\n"
    return code

def store_all_variables(variables):
    code = "\n/////////////STORE VARIBLES///////////////\n"
    for variable in variables:
        code += push_variable(variable)
    code += "///////////////////////////////////////////\n\n"
    return code

def store_args(args):
    code = "\n//--------STORE ARGS------------------\n"
    for arg in reversed(args):
        code += push_variable(arg)
    code += "\n//----------------------------------------\n\n"
    return code

def load_all_registers(registers):
    code = "//^^^^^^^^^^^^^LOAD REGS^^^^^^^^^^^^^^^^^^^\n"
    for register in reversed(registers):
        code += pop_variable(register.place)
    code += "//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n"
    return code

def load_all_variables(variables):
    code = "\n//^^^^^^^^^^^LOAD VARIBLES^^^^^^^^^^^^^^^^\n"
    for variable in reversed(variables):
        code += pop_variable(variable)
    code += "//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n"
    return code