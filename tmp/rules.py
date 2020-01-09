def p_empty(p):
    'empty :'
    pass


def p_program(p):
    r'''program  : macros classes '''


def p_macros(p):
    r'''macros  : macros macro
        | empty'''


def p_macro(p):
    r'''macro  : reference'''


def p_reference(p):
    r'''reference : REFERENCE STRING '''


def p_classes(p):
    r'''classes  : classes class
        | empty'''


def p_class(p):
    r'''class  : CLASS ID RCB symbol_decs LCB '''


def p_symbol_decs(p):
    r'''symbol_decs  : symbol_decs symbol_dec
        | empty'''


def p_symbol_dec(p):
    r'''symbol_dec  : var_dec
        | func_dec'''


def p_var_dec(p):
    r'''var_dec  : var_type var_list SEMICOLON '''


def p_var_type(p):
    r'''var_type  : return_type
        | STATIC return_type '''


def p_return_type(p):
    r'''return_type  : INT_TYPE
        | REAL_TYPE
        | BOOL_TYPE
        | STRING_TYPE
        | ID'''


def p_var_list(p):
    r'''var_list  : var_list COMMA var_list_item
        | var_list_item'''


def p_var_list_item(p):
    r'''var_list_item  : ID 
        | ID ASSIGNMENT exp'''


def p_func_dec(p):
    r'''func_dec  : var_type func_body 
        | VOID func_body
        | STATIC VOID func_body'''


def p_func_body(p):
    r'''func_body  : ID LP formal_arguments RP block '''


def p_formal_arguments(p):
    r'''formal_arguments  : formal_arguments_list
        | empty'''


def p_formal_arguments_list(p):
    r'''formal_arguments_list  : formal_arguments_list COMMA formal_argument
        | formal_argument'''


def p_formal_argument(p):
    r'''formal_argument  : return_type ID '''


def p_block(p):
    r'''block  : RCB statements_list LCB
        | statement'''


def p_statements_list(p):
    r'''statements_list  : statements_list statement
        | empty '''


def p_statement(p):
    '''statement  : SEMICOLON
    | exp SEMICOLON
    | assignment
    | print
    | statement_var_dec
    | if
    | for
    | while
    | return
    | break
    | continue'''


def p_assignment(p):
    r'''assignment  : lvalue EQ exp SEMICOLON '''


def p_lvalue(p):
    r'''lvalue  : ID
        | ID DOT ID'''


def p_print(p):
    r'''print  : PRINT LP STRING RP SEMICOLON '''


def p_statement_var_dec(p):
    r'''statement_var_dec  : return_type var_list SEMICOLON'''


def p_if(p):
    r'''if  : IF LP exp RP block elseif_blocks else_block '''


def p_elseif_blocks(p):
    r'''elseif_blocks  : elseifs
        | empty'''


def p_elseifs(p):
    r'''elseifs  : elseifs elseif
        | elseif'''


def p_elseif(p):
    r'''elseif  : ELSEIF LP exp RP block '''


def p_else_block(p):
    r'''else_block  : ELSE block
        | empty'''


def p_for(p):
    r'''for  : FOR LP ID IN exp TO exp STEPS exp RP block '''


def p_while(p):
    r'''while  : WHILE LP exp RP block'''


def p_return(p):
    r'''return  : RETURN exp SEMICOLON'''


def p_break(p):
    r'''break  : BREAK SEMICOLON'''


def p_continue(p):
    r'''continue  : CONTINUE SEMICOLON'''


def p_exp(p):
    r'''exp  : INTEGER
        | REAL
        | TRUE
        | FALSE
        | STRING
        | lvalue
        | binary_operation
        | logical_operation
        | comparison_operation
        | bitwise_operation
        | unary_operation
        | LP exp RP
        | function_call'''


def p_binary_operation(p):
    r'''binary_operation  : exp ADDITION exp
        | exp SUBTRACTION exp
        | exp MULTIPLICATION exp
        | exp DIVISION exp
        | exp MODULO exp
        | exp POWER exp
        | exp SHIFT_LEFT exp
        | exp SHIFT_RIGHT exp'''


def p_logical_operation(p):
    r'''logical_operation  : exp AND exp
        | exp OR exp'''


def p_comparison_operation(p):
    r'''comparison_operation  : exp LT exp
        | exp LE exp
        | exp GT exp 
        | exp GE exp
        | exp EQ exp
        | exp NE exp'''


def p_bitwise_operation(p):
    r'''bitwise_operation  : exp BITWISE_AND exp 
        | exp BITWISE_OR exp'''


def p_unary_operation(p):
    r'''unary_operation  : SUBTRACTION exp 
        | NOT exp
        | BITWISE_NOT exp'''


def p_function_call(p):
    r'''function_call  : ID function_call_body
        | ID DOT ID function_call_body '''


def p_function_call_body(p):
    r'''function_call_body  : LP actual_arguments RP'''


def p_actual_arguments(p):
    r'''actual_arguments  : actual_arguments_list
        | empty'''


def p_actual_arguments_list(p):
    r'''actual_arguments_list  : actual_arguments_list COMMA exp
            | exp'''


def p_error(p):
    print("Syntax error in input!")
