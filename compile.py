from lexer import Lexer
from parser import Parser

if __name__ == "__main__":
    lexer = Lexer().build()
    # with open("test-cases/test1.txt", "r") as f:
    with open("test-cases/function/negation.txt", "r") as f:
        with open("test-cases/boolean/negation.c", "w") as fo:
            text_input = f.read()

            lexer = Lexer().build()
            parser = Parser(fo)
            parser.build().parse(text_input, lexer, False)
