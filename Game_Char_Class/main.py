#AW Game Character Classes

class Character():
    def __init__(self, name, level):
        self.name = name
        self.level = level

class Assasin(Character):
    def __init__(self, name, level, speed, stealth):
        super().__init__(name, level)
        self.speed = speed
        self.stealth = stealth

