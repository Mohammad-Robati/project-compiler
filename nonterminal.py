class NoneTerminal:

    def __init__(self, rule):
        self.rule = rule
        self.place = "EMPTY"
        self.rtype = [None]
        self.value = ""
        self.code = ""

        self.true = ""
        self.false = ""
        self.begin = ""
        self.ifexp = None
        self.label = ""
        self.quad = []
        self.parameters = []
        self.number = ""
    
    def get_value(self):
        if self.place == "EMPTY":
            return str(self.value)
        return str(self.place)
        