class Register:
    NUM = 0
    Registers = []

    def __init__(self, rtype):
        self.num = Register.NUM
        Register.NUM += 1
        self.place = "t" + str(self.num)
        Register.Registers.append(self)
        
class Label:
    NUM = 0

    def __init__(self):
        self.num = Label.NUM
        Label.NUM += 1
        self.label = "L" + str(self.num)