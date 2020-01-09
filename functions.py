from register import Register

TRUE_LABEL = "TRUE_LABEL"
FALSE_LABEL = "FALSE_LABEL"
NEXT_LABEL = "NEXT_LABEL"

def binary_operation_code(p):
    reg = Register('double')

    p[0].place = reg.place
    p[0].code = p[1].code + p[3].code +  p[0].place + " = " + p[1].get_value() + " " + p[2] + " " + p[3].get_value() + ";\n"

def comparison_operation_code(p):
    p[0].code = p[1].code + p[3].code + "if(" + p[1].get_value() + p[2] + p[3].get_value() + ") goto " + TRUE_LABEL + ";\n" + "goto " + FALSE_LABEL + ";\n\n"

def back_patch_true(exp, true_label):
    exp.code = exp.code.replace(TRUE_LABEL, true_label.label)

def back_patch_false(exp, false_label):
    exp.code = exp.code.replace(FALSE_LABEL, false_label.label)

def back_patch_next(exp, next_label):
    exp.code = exp.code.replace(NEXT_LABEL, next_label.label)