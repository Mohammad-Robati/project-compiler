from ply import yacc
from lexer import Lexer

from nonterminal import NoneTerminal
from functions import *
from register import Register, Label


class Parser:
    tokens = Lexer().tokens

    def __init__(self, fileo):
        self.fileo = fileo
        pass

    def p_program(self, p):
        r'''program :   macros classes '''
        p[0] = NoneTerminal(p)
        head = '''
#include <stdio.h>
'''

        p[0].code = head + p[2].code
        self.fileo.write(p[0].code)

    def p_empty(self, p):
        r'''empty :  %prec PREC3'''
        # p[0] = NoneTerminal(p)

################################################## MACROSSSSSSSS #############################################################
    def p_macros_1(self, p):
        r'''macros :   macros macro'''
        # p[0] = NoneTerminal(p)

    def p_macros_2(self, p):
        r'''macros :   empty'''
        # p[0] = NoneTerminal(p)

    def p_macro(self, p):
        r'''macro :   reference'''
        # p[0] = NoneTerminal(p)

    def p_reference(self, p):
        r'''reference :  REFERENCE STRING '''
        # p[0] = NoneTerminal(p)
################################################## END OF MACROS :D #############################################################

################################################## CLASESSSSSSSS #############################################################
    def p_classes_1(self, p):
        r'''classes :   classes class'''
        p[0] = NoneTerminal(p)

        p[0].code = p[1].code + p[2].code

    def p_classes_2(self, p):
        r'''classes :   empty'''
        p[0] = NoneTerminal(p)
        p[0].code = ""

    def p_class(self, p):
        r'''class :   CLASS ID LCB symbol_decs RCB '''
        p[0] = NoneTerminal(p)
        p[0].code = p[4].code
################################################## END OF MACROS :D #############################################################

################################################## SYMBOL DECS ###############################################################
    def p_symbol_decs_1(self, p):
        r'''symbol_decs : symbol_decs symbol_dec'''
        p[0] = NoneTerminal(p)
        p[0].code = p[1].code + p[2].code

    def p_symbol_decs_2(self, p):
        r'''symbol_decs :   empty'''
        p[0] = NoneTerminal(p)
        p[0].code = ""

    def p_symbol_dec_1(self, p):
        r'''symbol_dec :   var_dec'''
        p[0] = NoneTerminal(p)
        p[0].code = p[1].code

    def p_symbol_dec_2(self, p):
        r'''symbol_dec :   func_dec'''
        p[0] = NoneTerminal(p)
        p[0].code = p[1].code
################################################ END OF SYMBOL DECS :D #########################################################

################################################ VAR DEC & RETURN_TYPE ######################################################
    def p_var_dec(self, p):
        r'''var_dec :   var_type var_list SEMICOLON '''
        p[0] = NoneTerminal(p)
        p[0].code = p[1].code + " " + p[2].code + ";"

    def p_var_type_1(self, p):
        r'''var_type :   return_type'''
        p[0] = NoneTerminal(p)
        p[0].code = p[1].code

    def p_var_type_2(self, p):
        r'''var_type :   STATIC return_type '''
        p[0] = NoneTerminal(p)
        p[0].code = "WE DONT WANNA IMP IT!"

    def p_return_type_1(self, p):
        r'''return_type :   INT_TYPE'''
        p[0] = NoneTerminal(p)
        p[0].code = "int"

    def p_return_type_2(self, p):
        r'''return_type :   REAL_TYPE'''
        p[0] = NoneTerminal(p)
        p[0].code = "double"

    def p_return_type_3(self, p):
        r'''return_type :   BOOL_TYPE'''
        p[0] = NoneTerminal(p)
        p[0].code = "bool"

    def p_return_type_4(self, p):
        r'''return_type :   STRING_TYPE'''
        p[0] = NoneTerminal(p)
        p[0].code = "char*"

    def p_return_type_5(self, p):
        r'''return_type :   ID'''
        p[0] = NoneTerminal(p)
        p[0].code = "here?"
################################################ VAR DEC & RETURN_TYPE #######################################################

##################################################### VAR LIST ############################################################
    def p_var_list_1(self, p):
        r'''var_list :  var_list COMMA var_list_item'''
        p[0] = NoneTerminal(p)
        p[0].code = p[1].code + ", " + p[3].code

    def p_var_list_2(self, p):
        r'''var_list :   var_list_item'''
        p[0] = NoneTerminal(p)
        p[0].code = p[1].code

    def p_var_list_item_1(self, p):
        r'''var_list_item :   ID'''
        p[0] = NoneTerminal(p)
        p[0].code = p[1]

    def p_var_list_item_2(self, p):
        r'''var_list_item : ID ASSIGNMENT exp'''
        p[0] = NoneTerminal(p)
        p[0].code = p[3].code +  p[1] + " = " + p[3].get_value()
##################################################### VAR LIST ##############################################################

##################################################### FUNCTIONS ############################################################
    def p_func_dec(self, p):
        r'''func_dec :   var_type func_body '''
        p[0] = NoneTerminal(p)
        p[0].code = "FUNCTION NOT YET!"

    def p_func_dec_1(self, p):
        r'''func_dec :   VOID func_body'''
        p[0] = NoneTerminal(p)
        p[0].code = "FUNCTION NOT YET!"

    def p_func_dec_2(self, p):
        r'''func_dec :   STATIC VOID func_body'''
        p[0] = NoneTerminal(p)
        p[0].code = "// Functions not yet \nvoid " + p[3].code

    def p_func_body(self, p):
        r'''func_body :   ID LP formal_arguments RP block '''
        p[0] = NoneTerminal(p)
        registers = ""
        if len(Register.Registers) > 0:
            registers = "double " + " ,".join((reg.place for reg in Register.Registers)) + ";\n"
        p[0].code = "main()\n{\n\n"+ registers + "\n" +  p[5].code + "\n\n}"
##################################################### FUNCTIONS ############################################################


##################################################### FORMAL ARGUMENTS #####################################################
    def p_formal_arguments_1(self, p):
        r'''formal_arguments :   formal_arguments_list'''
        p[0] = NoneTerminal(p)

    def p_formal_arguments_2(self, p):
        r'''formal_arguments :   empty'''
        p[0] = NoneTerminal(p)

    def p_formal_arguments_list_1(self, p):
        r'''formal_arguments_list :   formal_arguments_list COMMA formal_argument'''
        p[0] = NoneTerminal(p)

    def p_formal_arguments_list_2(self, p):
        r'''formal_arguments_list :   formal_argument'''
        p[0] = NoneTerminal(p)

    def p_formal_argument(self, p):
        r'''formal_argument :   return_type ID '''
        p[0] = NoneTerminal(p)
##################################################### FORMAL ARGUMENTS #####################################################

##################################################### BLOCK & STATEMENTS ###################################################
    def p_block_1(self, p):
        r'''block :   LCB statements_list RCB'''
        p[0] = NoneTerminal(p)
        
        p[0].code = p[2].code

    def p_block_2(self, p):
        r'''block :   statement'''
        p[0] = NoneTerminal(p)
        p[0].code = p[1].code

    def p_statements_list_1(self, p):
        r'''statements_list :   statements_list statement'''
        p[0] = NoneTerminal(p)
        p[0].code = p[1].code + p[2].code

    def p_statements_list_2(self, p):
        r'''statements_list :   empty '''
        p[0] = NoneTerminal(p)
        p[0].code = ""

    def p_statement_1(self, p):
        r'''statement :   SEMICOLON '''
        p[0] = NoneTerminal(p)
        p[0].code = ";"

    def p_statement_2(self, p):
        r'''statement :   exp SEMICOLON'''
        p[0] = NoneTerminal(p)
        p[0].code = p[1].code + ";\n"

    def p_statement_3(self, p):
        r'''statement :   assignment'''
        p[0] = NoneTerminal(p)
        p[0].code = p[1].code

    def p_statement_4(self, p):
        r'''statement :   print'''
        p[0] = NoneTerminal(p)
        p[0].code = "#########PRINT########"

    def p_statement_5(self, p):
        r'''statement :   statement_var_dec'''
        p[0] = NoneTerminal(p)
        p[0].code = p[1].code

    def p_statement_6(self, p):
        r'''statement :   if '''
        p[0] = NoneTerminal(p)
        p[0].code = p[1].code

    def p_statement_7(self, p):
        r'''statement :   for'''
        p[0] = NoneTerminal(p)
        p[0].code = p[1].code

    def p_statement_8(self, p):
        r'''statement :   while'''
        p[0] = NoneTerminal(p)
        p[0].code = p[1].code

    def p_statement_9(self, p):
        r'''statement :   return'''
        p[0] = NoneTerminal(p)
        p[0].code = "#######RETURN##########"

    def p_statement_10(self, p):
        r'''statement :   break'''
        p[0] = NoneTerminal(p)
        p[0].code = "#######BREAK##########"

    def p_statement_11(self, p):
        r'''statement :   continue'''
        p[0] = NoneTerminal(p)
        p[0].code = "#######CONTINUE##########"
##################################################### BLOCK & STATEMENTS ###################################################

######################################################## ASSIGNMENTS #######################################################
    def p_assignment(self, p):
        r'''assignment :   lvalue ASSIGNMENT exp SEMICOLON '''
        p[0] = NoneTerminal(p)
        p[0].code = p[3].code + p[1].place + " = " + p[3].get_value() + ";\n"
        
    def p_lvalue_1(self, p):
        r'''lvalue :   ID'''
        p[0] = NoneTerminal(p)
        p[0].place = p[1]

    def p_lvalue_2(self, p):
        r'''lvalue :   ID DOT ID'''
        p[0] = NoneTerminal(p)
        p[0].code = ("WE DONT IMP IT (CLASS.)")
######################################################## ASSIGNMENTS #######################################################

    def p_print(self, p):
        r'''print :   PRINT LP STRING RP SEMICOLON '''
        p[0] = NoneTerminal(p)
        p[0].code = "#####PRINT NOT YET"

    def p_statement_var_dec(self, p):
        r'''statement_var_dec :   return_type var_list SEMICOLON'''
        p[0] = NoneTerminal(p)
        p[0].code = p[1].code + " " + p[2].code + ";\n"

########################################################### IFS ###########################################################
    def p_if(self, p):
        r'''if :   IF LP exp RP block elseif_blocks else_block'''

        p[3].code = p[3].ifexp if p[3].ifexp else ""

        p[0] = NoneTerminal(p)

        p[0].true = Label()
        p[0].next = Label()
        falselabel = None

        #back patch true block
        back_patch_true(p[3], p[0].true)

        elsifblock = ""
        elseblock = ""

        elselabel = None
        #create label for else block and set next for it
        if p[7].code:
            elselabel = Label()
            elseblock = elselabel.label + ": //else\n" + p[7].code 

        elseiflabel = None
        #check wheter there is elseif block
        if p[6].code:
            elseiflabel = Label()
            back_patch_false(p[3], elseiflabel)
            falselabel = elseiflabel

            back_patch_next(p[6], p[0].next)

            #check for else
            if p[7].code:
                back_patch_false(p[6], elselabel)
            else:
                back_patch_false(p[6], p[0].next)
            
            elsifblock = elseiflabel.label + ": //elseifs\n" + p[6].code 

        elif p[7].code:
            back_patch_false(p[3], elselabel)
            falselabel = elselabel
        else:
            back_patch_false(p[3], p[0].next)
            falselabel = None 
        
        true_block = p[0].true.label + ": " + p[5].code + "goto " + p[0].next.label + "; //next label\n\n"

        false_block = ""
        if falselabel:
            false_block = elsifblock + elseblock
        
        next_block = p[0].next.label + ": //end of if statement - next\n"

        p[0].code = "// if statement\n" +  p[3].code + true_block + false_block + next_block


    def p_elseif_blocks_1(self, p):
        r'''elseif_blocks :   elseifs %prec PREC2'''
        p[0] = NoneTerminal(p)
        p[0].code = p[1].code

    def p_elseif_blocks_2(self, p):
        r'''elseif_blocks : '''
        p[0] = NoneTerminal(p)
        p[0].code = None

    def p_elseifs_1(self, p):
        r'''elseifs :   elseifs elseif %prec PREC2'''
        p[0] = NoneTerminal(p)

        elseif_label = Label()
        back_patch_false(p[1], elseif_label)
        p[0].code = p[1].code + elseif_label.label + ": //elseif \n" + p[2].code + "\n"

    def p_elseifs_2(self, p):
        r'''elseifs :   elseif'''
        p[0] = NoneTerminal(p)
        p[0].code = p[1].code

    def p_elseif(self, p):
        r'''elseif :   ELSEIF LP exp RP block %prec PREC1'''
        p[0] = NoneTerminal(p)

        truelabel = Label()
        back_patch_true(p[3], truelabel)
        p[0].code = p[3].code + truelabel.label + ": //elseif epression\n" + p[5].code + "goto " +  NEXT_LABEL + "; // next label\n\n"

    def p_else_block_1(self, p):
        r'''else_block : ELSE block'''
        p[0] = NoneTerminal(p)
        p[0].code = p[2].code + "\n"

    def p_else_block_2(self, p):
        r'''else_block : '''
        p[0] = NoneTerminal(p)
        p[0].code = ""
########################################################### IFS ###########################################################

########################################################### FORS ###########################################################
    def p_for(self, p):
        r'''for :   FOR LP ID IN exp TO exp STEPS exp RP block '''
        p[0] = NoneTerminal(p)

        begin = Label()
        code_begin = Label()
        after = Label()

        initialization = "int " + p[3] + ";\n" + p[3] + " = " + p[5].get_value() + "; // FOR initialization\n"

        check_bundry = "if ( " + p[3] + " < " + p[7].get_value() + " ) goto " + code_begin.label + "; // FOR check\n"
        check_bundry += "goto " + after.label + ";\n\n"

        iteration = p[3] + " = " + p[3] + " + " + p[9].get_value() + "; // FOR iteration\n"

        p[0].code = "// FOR BEGIN\n\n" + p[5].code + p[9].code + initialization \
                     + begin.label + ": // for begin\n\n" + p[7].code + check_bundry \
                     + code_begin.label + ": // for code begin\n" + p[11].code + iteration \
                     + "goto " + begin.label + "; //back to for begin\n\n" + after.label+ ": // end of for\n\n"

    def p_while(self, p):
        r'''while :   WHILE LP exp RP block'''
        p[0] = NoneTerminal(p)

        begin = Label()
        code_begin = Label()
        after = Label()

        back_patch_false(p[3], after)
        back_patch_true(p[3], code_begin)
        p[0].code = begin.label + ": // while begin\n\n" + p[3].code + code_begin.label + ": // while code begin\n" + p[5].code \
                     + "goto " + begin.label + "; //back to while begin\n\n" + after.label+ ": // end of while\n\n"

    def p_return(self, p):
        r'''return :   RETURN exp SEMICOLON'''
        p[0] = NoneTerminal(p)

    def p_break(self, p):
        r'''break :   BREAK SEMICOLON'''
        p[0] = NoneTerminal(p)

    def p_continue(self, p):
        r'''continue :   CONTINUE SEMICOLON'''
        p[0] = NoneTerminal(p)
########################################################### FORS ###########################################################

##################################################### EXPRESSION ###########################################################
    def p_exp_1(self, p):
        r'''exp :   INTEGER'''
        p[0] = NoneTerminal(p)
        p[0].value = p[1]

    def p_exp_2(self, p):
        r'''exp :   REAL'''
        p[0] = NoneTerminal(p)
        p[0].value = p[1]

    def p_exp_3(self, p):
        r'''exp :   TRUE'''
        p[0] = NoneTerminal(p)
        p[0].value = p[1]

    def p_exp_4(self, p):
        r'''exp :   FALSE'''
        p[0] = NoneTerminal(p)
        p[0].value = p[1]

    def p_exp_5(self, p):
        r'''exp :   STRING'''
        p[0] = NoneTerminal(p)
        p[0].value = p[1]

    def p_exp_6(self, p):
        r'''exp :   lvalue'''
        p[0] = NoneTerminal(p)
        p[0].place = p[1].place
        p[0].ifexp = "if ( " + p[1].place + " != 0) goto " + TRUE_LABEL + ";\n" + "goto " + FALSE_LABEL + ";\n\n"

    def p_exp_7(self, p):
        r'''exp :   binary_operation'''
        p[0] = NoneTerminal(p)
        p[0].code = p[1].code
        p[0].place = p[1].get_value()

    def p_exp_8(self, p):
        r'''exp :   logical_operation'''
        p[0] = NoneTerminal(p)
        p[0].code = p[1].code

    def p_exp_9(self, p):
        r'''exp :   comparison_operation'''
        p[0] = NoneTerminal(p)
        p[0].code = p[1].code

    def p_exp_10(self, p):
        r'''exp :   bitwise_operation'''
        p[0] = NoneTerminal(p)
        p[0].code = "NOT YET BITWISE"

    def p_exp_11(self, p):
        r'''exp :   unary_operation'''
        p[0] = NoneTerminal(p)
        p[0].code = "NOT YET UNARY"

    def p_exp_12(self, p):
        r'''exp :   LP exp RP'''
        p[0] = NoneTerminal(p)
        p[0].place = p[2].place
        p[0].code = p[2].code

    def p_exp_13(self, p):
        r'''exp :   function_call'''
        p[0] = NoneTerminal(p)
        p[0].code = "NOT YET FUNCTION CALL"
##################################################### EXPRESSION ###########################################################

################################################### BINARY OPERATION #######################################################
    def p_binary_operation_1(self, p):
        r'''binary_operation :   exp ADDITION exp'''
        p[0] = NoneTerminal(p)
        binary_operation_code(p)

    def p_binary_operation_2(self, p):
        r'''binary_operation :   exp SUBTRACTION exp'''
        p[0] = NoneTerminal(p)
        binary_operation_code(p)

    def p_binary_operation_3(self, p):
        r'''binary_operation :   exp MULTIPLICATION exp'''
        p[0] = NoneTerminal(p)
        binary_operation_code(p)

    def p_binary_operation_4(self, p):
        r'''binary_operation :   exp DIVISION exp'''
        p[0] = NoneTerminal(p)
        binary_operation_code(p)

    def p_binary_operation_5(self, p):
        r'''binary_operation :   exp MODULO exp'''
        p[0] = NoneTerminal(p)
        binary_operation_code(p)

    def p_binary_operation_6(self, p):
        r'''binary_operation :   exp POWER exp'''
        p[0] = NoneTerminal(p)
        binary_operation_code(p)

    def p_binary_operation_7(self, p):
        r'''binary_operation :   exp SHIFT_LEFT exp'''
        p[0] = NoneTerminal(p)
        binary_operation_code(p)

    def p_binary_operation_8(self, p):
        r'''binary_operation :   exp SHIFT_RIGHT exp'''
        p[0] = NoneTerminal(p)
        binary_operation_code(p)
################################################### BINARY OPERATION #######################################################

################################################## OTHER OPERATION #######################################################
    def p_logical_operation_9(self, p):
        r'''logical_operation :   exp AND exp'''
        p[0] = NoneTerminal(p)

        true_label = Label()
        back_patch_true(p[1], true_label)
        p[0].code = p[1].code + true_label + ": // logical calculation (AND)\n" + p[2].code


    def p_logical_operation_10(self, p):
        r'''logical_operation :   exp OR exp'''
        p[0] = NoneTerminal(p)

        false_label = Label()
        back_patch_false(p[0], false_label)
        p[0].code = p[1].code + false_label + ": // logical calculation (OR)\n" + p[2].code

    def p_comparison_operation_1(self, p):
        r'''comparison_operation :   exp LT exp'''
        p[0] = NoneTerminal(p)
        comparison_operation_code(p)

    def p_comparison_operation_2(self, p):
        r'''comparison_operation :   exp LE exp'''
        p[0] = NoneTerminal(p)
        comparison_operation_code(p)

    def p_comparison_operation_3(self, p):
        r'''comparison_operation :   exp GT exp '''
        p[0] = NoneTerminal(p)
        comparison_operation_code(p)

    def p_comparison_operation_4(self, p):
        r'''comparison_operation :   exp GE exp'''
        p[0] = NoneTerminal(p)
        comparison_operation_code(p)

    def p_comparison_operation_5(self, p):
        r'''comparison_operation :   exp EQ exp'''
        p[0] = NoneTerminal(p)
        comparison_operation_code(p)

    def p_comparison_operation_6(self, p):
        r'''comparison_operation :   exp NE exp'''
        p[0] = NoneTerminal(p)
        comparison_operation_code(p)
################################################## OTHER OPERATION #######################################################

################################################ BITWISE OPERATION #######################################################
    def p_bitwise_operation_1(self, p):
        r'''bitwise_operation :   exp BITWISE_AND exp '''
        p[0] = NoneTerminal(p)
        binary_operation_code(p)

    def p_bitwise_operation_2(self, p):
        r'''bitwise_operation :   exp BITWISE_OR exp'''
        p[0] = NoneTerminal(p)
        binary_operation_code(p)
################################################ BITWISE OPERATION #######################################################

################################################ UNARY OPERATION #######################################################
    def p_unary_operation_1(self, p):
        r'''unary_operation :   SUBTRACTION exp '''
        p[0] = NoneTerminal(p)
        p[0].code = "UNARY NOT YET" 

    def p_unary_operation_2(self, p):
        r'''unary_operation :   NOT exp'''
        p[0] = NoneTerminal(p)
        p[0].code = "UNARY NOT YET" 

    def p_unary_operation_3(self, p):
        r'''unary_operation :   BITWISE_NOT exp'''
        p[0] = NoneTerminal(p)
        p[0].code = "UNARY NOT YET" 
################################################ UNARY OPERATION #######################################################

################################################ FUNCTION CALL #######################################################
    def p_function_call_1(self, p):
        r'''function_call :   ID function_call_body'''
        p[0] = NoneTerminal(p)

    def p_function_call_2(self, p):
        r'''function_call :   ID DOT ID function_call_body '''
        p[0] = NoneTerminal(p)

    def p_function_call_body(self, p):
        r'''function_call_body :   LP actual_arguments RP'''
        p[0] = NoneTerminal(p)

    def p_actual_arguments_1(self, p):
        r'''actual_arguments :   actual_arguments_list'''
        p[0] = NoneTerminal(p)

    def p_actual_arguments_2(self, p):
        r'''actual_arguments :   empty'''
        p[0] = NoneTerminal(p)

    def p_actual_arguments_list_1(self, p):
        r'''actual_arguments_list :   actual_arguments_list COMMA exp'''
        p[0] = NoneTerminal(p)

    def p_actual_arguments_list_2(self, p):
        r'''actual_arguments_list :   exp'''
        p[0] = NoneTerminal(p)
################################################ FUNCTION CALL #######################################################

    def p_error(self, p):
        raise Exception('ParsingError: invalid grammar at ', p)

    precedence = (
        ('left', 'AND', 'OR'),
        ('left', 'NOT'),
        ('left', 'LT', 'LE', 'GT', 'GE', 'EQ', 'NE'),
        ('left', 'ADDITION', 'SUBTRACTION'),
        ('left', 'MULTIPLICATION', 'DIVISION'),
        ('left', 'MODULO'),
        ('left', 'POWER'),
        ('left', 'SHIFT_LEFT', 'SHIFT_RIGHT'),
        ('left', 'BITWISE_AND', 'BITWISE_OR', 'BITWISE_NOT'),

        ('right', 'PREC3'),
        ('right', 'PREC2'),
        ('right', 'PREC1'),
        ('right', 'ELSEIF')
    )

    def build(self, **kwargs):
        r'''build : the parser'''
        self.parser = yacc.yacc(module=self, **kwargs)
        return self.parser
