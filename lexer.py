from ply import lex


class Lexer():
    tokens = (
        'ID',
        'INTEGER',
        'REAL',
        'STRING',
        'CLASS',
        'REFERENCE',
        'STATIC',
        'INT_TYPE',
        'REAL_TYPE',
        'BOOL_TYPE',
        'STRING_TYPE',
        'VOID',
        'TRUE',
        'FALSE',
        'PRINT',
        'RETURN',
        'BREAK',
        'CONTINUE',
        'IF',
        'ELSE',
        'ELSEIF',
        'WHILE',
        'FOR',
        'TO',
        'IN',
        'STEPS',
        'BITWISE_AND',
        'AND',
        'BITWISE_OR',
        'OR',
        'NOT',
        'BITWISE_NOT',
        'SHIFT_RIGHT',
        'SHIFT_LEFT',
        'ASSIGNMENT',
        'ADDITION',
        'SUBTRACTION',
        'MULTIPLICATION',
        'DIVISION',
        'MODULO',
        'POWER',
        'GT',
        'GE',
        'LT',
        'LE',
        'EQ',
        'NE',
        'LCB',
        'RCB',
        'LP',
        'RP',
        'DOT',
        'SEMICOLON',
        'COMMA',
        'ERROR'
    )

    reserved = {
        # Conditional
        'If': 'IF',
        'Then': 'THEN',
        'Else': 'ELSE',
        # Loops
        'For': 'FOR',
        'While': 'WHILE',
        # Types
        'Int': 'INT',
        'Bool': 'BOOL',
        'Real': 'REAL',
        # Other Keywords
        'Program': 'PROGRAM',
        'Print': 'PRINT',
        'To': 'TO',
        'True': 'TRUE',
        'False': 'FALSE',
        'Downto': 'DOWNTO',
        'Do': 'DO',
        'Return': 'RETURN',
        'Case': 'CASE',
        'Function': 'FUNCTION',
        'Procedure': 'PROCEDURE',
        'Begin': 'BEGIN',
        'End': 'END',
    }

    DIGIT = '([0-9])'
    ALPHABET = '([a-zA-Z])'
    NOT_ALPHABET = '([^a-zA-Z])'
    ALPHANUMERICAL = '(' + DIGIT + '|' + ALPHABET + ')'
    ALPHANUMERICAL_UNDERSCORE_PAIR = '(' + ALPHANUMERICAL + '[_]' + ')'
    ALPHANUMERICAL_PAIR = '(' + ALPHANUMERICAL + ALPHANUMERICAL + ')'

    t_ignore = r'([ \t\n]+)|(["][^"]*["]([ \t\n]*[+][ \t\n]*["][^"]*["])*)'

    def t_error(self, token):
        return token

    def t_INT_TYPE(self, token):
        r'int'
        return token

    def t_REAL_TYPE(self, token):
        r'real'
        return token

    def t_STRING_TYPE(self, token):
        r'string'
        return token

    def t_BREAK(self, token):
        r'break'
        return token

    def t_CONTINUE(self, token):
        r'continue'
        return token

    def t_IF(self, token):
        r'if'
        return token

    def t_ELSE(self, token):
        r'else'
        return token

    def t_ELSEIF(self, token):
        r'elseif'
        return token

    def t_WHILE(self, token):
        r'while'
        return token

    def t_FOR(self, token):
        r'fo	r'
        return token

    def t_TO(self, token):
        r'to'
        return token

    def t_IN(self, token):
        r'in'
        return token

    def t_STEPS(self, token):
        r'steps'
        return token

    def t_CLASS(self, token):
        r'class'
        return token

    def t_REFERENCE(self, token):
        r'reference'
        return token

    def t_STATIC(self, token):
        r'static'
        return token

    def t_BOOL_TYPE(self, token):
        r'bool'
        return token

    def t_VOID(self, token):
        r'void'
        return token

    def t_TRUE(self, token):
        r'true'
        return token

    def t_FALSE(self, token):
        r'false'
        return token

    def t_PRINT(self, token):
        r'print'
        return token

    def t_RETURN(self, token):
        r'return'
        return token

    def t_BITWISE_AND(self, token):
        r'&'
        return token

    def t_AND(self, token):
        r'&&'
        return token

    def t_BITWISE_OR(self, token):
        r'\|'
        return token

    def t_OR(self, token):
        r'\|\|'
        return token

    def t_NOT(self, token):
        r'!'
        return token

    def t_BITWISE_NOT(self, token):
        r'~'
        return token

    def t_SHIFT_RIGHT(self, token):
        r'>>'
        return token

    def t_SHIFT_LEFT(self, token):
        r'\<\<'
        return token

    def t_ASSIGNMENT(self, token):
        r'\='
        return token

    def t_ADDITION(self, token):
        r'\+'
        return token

    def t_SUBTRACTION(self, token):
        r'-'
        return token

    def t_MULTIPLICATION(self, token):
        r'\*'
        return token

    def t_DIVISION(self, token):
        r'\/'
        return token

    def t_MODULO(self, token):
        r'%'
        return token

    def t_POWER(self, token):
        r'\^'
        return token

    def t_GT(self, token):
        r'>'
        return token

    def t_GE(self, token):
        r'>\='
        return token

    def t_LT(self, token):
        r'\<'
        return token

    def t_LE(self, token):
        r'\<\='
        return token

    def t_EQ(self, token):
        r'=='
        return token

    def t_NE(self, token):
        r'!='
        return token

    def t_LCB(self, token):
        r'\''
        return token

    def t_RCB(self, token):
        r'\}'
        return token

    def t_LP(self, token):
        r'\('
        return token

    def t_RP(self, token):
        r'\)'
        return token

    def t_DOT(self, token):
        r'\.'
        return token

    def t_SEMICOLON(self, token):
        r';'
        return token

    def t_COMMA(self, token):
        r','
        return token

    def t_ID(self, token):
        r'''([a-zA-Z](([a-zA-Z][a-zA-Z]))*)|(([a-zA-Z](([a-zA-Z][a-zA-Z]))*)([_]([a-zA-Z0-9][_])*)[a-zA-Z0-9](([a-zA-Z][a-zA-Z]))*)|(([a-zA-Z](([a-zA-Z][a-zA-Z]))*[a-zA-Z0-9])?([_]([a-zA-Z0-9][_])*)(([a-zA-Z][a-zA-Z]))*)'''
        return token

    def t_INTEGER(self, token):
        r'0b1[10]*|0b0|[1-9][0-9]*|0[xX][1-9A-Fa-f][0-9A-Fa-f]*|0[xX]0|0'
        token.value = int(token.value, 0)
        return token

    def t_REAL(self, token):
        r'[1-9][0-9]*\.[0-9]*[1-9]'
        token.value = float(token.value)
        return token

    def t_STRING(self, token):
        r'"[^"]*"([ \t\n]*[+][ \t\n]*"[^"]*")*'
        token.value = token.value.replace('', '\"[ \n\t]*[+][ \n\t]*\"')
        return token

    def t_ERROR(self, token):
        r'[^ \t\n"-=^_<>+*/;,{}]+'
        print("ERROR:", token)
        exit()

    def build(self, **kwargs):
        '''
        build the lexer
        '''
        self.lexer = lex.lex(module=self, **kwargs)

        return self.lexer
