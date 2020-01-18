from lexer import Lexer
from parser import Parser
from functions import VARIABLES
from register import Register, Label
import os

# TEST_DIR = "tests"
TEST_DIR = "finaltests"
ANS_DIR = "answers"
'''
FILES = (
    "arithmetic/arithmetic",
    "arithmetic/average",

    "boolean/sum",
    "boolean/grade",
    "boolean/vectors",

    # "functions/combination",
    # "functions/negation",
    # "functions/factorial",
)'''

FILES = (
    # "1-Arithmetic/arithmetic",
    # "1-Arithmetic/variance",

    # "2-If/if",
    # "3-While/while",

    # "4-For/for",

    # "5-Function/function",

    # "6-Combination/add",
    # "6-Combination/fibonacci",
    # "6-Combination/palindrome",
    "6-Combination/prime",
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
        # print("gcc -o " + ans_loc + ".out " + ans_loc + ".c")
        # os.system("gcc -o " + ans_loc + ".out " + ans_loc + ".c")
        print()
