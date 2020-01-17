from lexer import Lexer
from parser import Parser
from functions import VARIABLES
from register import Register, Label
import os

TEST_DIR = "tests"
ANS_DIR = "answers"

FILES = (
    # "arithmetic/arithmetic",
    # "arithmetic/average",

    # "boolean/sum",
    # "boolean/grade",
    # "boolean/vectors",

    # "functions/combination",
    "functions/negation",
)

if __name__ == "__main__":
    for file in FILES:
        file_loc = TEST_DIR + "/" + file
        ans_loc = TEST_DIR + "/" + ANS_DIR + "/" + file
        with open(file_loc + ".txt", "r") as f:
            with open(file_loc + ".c", "w") as fo:
                text_input = f.read()

                # global VARIABLES
                # VARIABLES = []
                # Register.NUM = 0
                # Register.Registers = []
                # Label.NUM = 0

                lexer = Lexer().build()
                lexer = Lexer().build()
                parser = Parser(fo)
                parser.build().parse(text_input, lexer, False)

        
        print("test " + file)
        print("gcc -o " + file_loc + ".out " + file_loc + ".c")
        os.system("gcc -o " + file_loc + ".out " + file_loc + ".c")
        print("gcc -o " + ans_loc + ".out " + ans_loc + ".c")
        os.system("gcc -o " + ans_loc + ".out " + ans_loc + ".c")
        print()
