from lexer import Lexer
from parser import Parser

if __name__ == "__main__":
    lexer = Lexer().build()
    with open("test-cases/test1.txt", "r") as f:
        text_input = f.read()

        lexer = Lexer().build()
        parser = Parser()
        parser.build().parse(text_input, lexer, False)
