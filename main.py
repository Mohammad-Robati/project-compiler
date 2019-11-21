from ply import lex
from ply import yacc

from tokens import tokens

DIGIT = '([0-9])'
ALPHABET = '([a-zA-Z])'
NOT_ALPHABET = '([^a-zA-Z])'
ALPHANUMERICAL = '(' + DIGIT + '|' + ALPHABET + ')'
ALPHANUMERICAL_UNDERSCORE_PAIR = '(' + ALPHANUMERICAL + '[_]' + ')'
ALPHANUMERICAL_PAIR = '(' + ALPHANUMERICAL + ALPHANUMERICAL + ')'


t_ignore = r' \t\n'


def t_BREAK(token):
    r'break'
    return token


def t_CONTINUE(token):
    r'continue'
    return token


def t_IF(token):
    r'if'
    return token


def t_ELSE(token):
    r'else'
    return token


def t_ELSEIF(token):
    r'elseif'
    return token


def t_WHILE(token):
    r'while'
    return token


def t_FOR(token):
    r'for'
    return token


def t_TO(token):
    r'to'
    return token


def t_IN(token):
    r'in'
    return token


def t_STEPS(token):
    r'steps'
    return token


def t_CLASS(token):
    r'class'
    return token


def t_REFERENCE(token):
    r'reference'
    return token


def t_STATIC(token):
    r'static'
    return token


def t_INT_TYPE(token):
    r'int'
    return token


def t_REAL_TYPE(token):
    r'real'
    return token


def t_BOOL_TYPE(token):
    r'bool'
    return token


def t_STRING_TYPE(token):
    r'string'
    return token


def t_VOID(token):
    r'void'
    return token


def t_TRUE(token):
    r'true'
    return token


def t_FALSE(token):
    r'false'
    return token


def t_PRINT(token):
    r'print'
    return token


def t_RETURN(token):
    r'return'
    return token


def t_BITWISE_AND(token):
    r'&'
    return token


def t_AND(token):
    r'&&'
    return token


def t_BITWISE_OR(token):
    r'\|'
    return token


def t_OR(token):
    r'\|\|'
    return token


def t_NOT(token):
    r'!'
    return token


def t_BITWISE_NOT(token):
    r'~'
    return token


def t_SHIFT_RIGHT(token):
    r'>>'
    return token


def t_SHIFT_LEFT(token):
    r'\<\<'
    return token


def t_ASSIGNMENT(token):
    r'\='
    return token


def t_ADDITION(token):
    r'\+'
    return token


def t_SUBTRACTION(token):
    r'-'
    return token


def t_MULTIPLICATION(token):
    r'\*'
    return token


def t_DIVISION(token):
    r'\/'
    return token


def t_MODULO(token):
    r'%'
    return token


def t_POWER(token):
    r'\^'
    return token


def t_GT(token):
    r'>'
    return token


def t_GE(token):
    r'>\='
    return token


def t_LT(token):
    r'\<'
    return token


def t_LE(token):
    r'\<\='
    return token


def t_EQ(token):
    r'=='
    return token


def t_NE(token):
    r'!='
    return token


def t_LCB(token):
    r'\''
    return token


def t_RCB(token):
    r'\}'
    return token


def t_LP(token):
    r'\('
    return token


def t_RP(token):
    r'\)'
    return token


def t_DOT(token):
    r'\.'
    return token


def t_SEMICOLON(token):
    r';'
    return token


def t_COMMA(token):
    r','
    return token


t_ID = r'''({ALPHABET}({ALPHANUMERICAL_PAIR})*)|(({ALPHABET}({ALPHANUMERICAL_PAIR})*)([_]{ALPHANUMERICAL_UNDERSCORE_PAIR}*){ALPHANUMERICAL}({ALPHANUMERICAL_PAIR})*)|(({ALPHABET}({ALPHANUMERICAL_PAIR})*{ALPHANUMERICAL})?([_]{ALPHANUMERICAL_UNDERSCORE_PAIR}*)({ALPHANUMERICAL_PAIR})*)'''.format(ALPHABET=ALPHABET,
                                                                                                                                                                                                                                                                                                     ALPHANUMERICAL_PAIR=ALPHANUMERICAL_PAIR,
                                                                                                                                                                                                                                                                                                     ALPHANUMERICAL_UNDERSCORE_PAIR=ALPHANUMERICAL_UNDERSCORE_PAIR,
                                                                                                                                                                                                                                                                                                     ALPHANUMERICAL=ALPHANUMERICAL)


def t_error(token):
    r'[^ \t\n]+'


print(t_ID)
# t_ID = r'[a-zA-Z]+'
lex.lex()
if __name__ == "__main__":
    lex.input("break alii")
    while True:
        tok = lex.token()
        if not tok:
            break
        print(tok)
