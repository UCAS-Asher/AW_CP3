#AW Abstraction Notes
from abc import ABC, abstractmethod

#Why can't you create an object from an abstract class?
    #The class is a placeholder class

#How do abstract classes and abstract methods work together?
    #They are both made to be overwritten

#What does abc stand for?
    #Abstract base Class

#What are decorators? 
    #Decorators give further information on what follows and starts with @

#What is an abstract method?
    #A method written in a parent class designed to be changed in the child class

#What is a concrete method?
    #Normal methods

#What is an abstract class?
    #A placeholder class designed to be overwritten

#How do you make an abstract method?
    #type @abstractmethod before the method then change it in the child class

#How can you create a class that inherits from multiple parent classes?
    #do a comma then put the next class 

#Why does the inheritance order matter?
    #it determines what is inheritted from what

#What does the mro() method do when you call it on a class?
    #tells you the Method resolution order

#What is Method resolution order?
    #tells you which classes you inherit from first


class Animal(ABC):
    def __init__(self, name):
        self.name = name

    def __str__(self):
        return self.name

    @abstractmethod
    def move(self):
        pass

class Quadrupeds(Animal): 
    def __init__(self, name):
        super().__init__(name)

    def move(self):
        print(f"{self.name} can walk or run.")

class Aquatic(Animal):
    def __init__(self, name):
        super().__init__(name)

    def move(self):
        print(f"{self.name} can swim.")

class SeaLion(Aquatic, Quadrupeds):
    def __init__(self, name):
        super().__init__(name)

    def eats(self):
        print(f"{self.name} eats penguins and krill")

sealion = SeaLion("Greg")
print(sealion)
sealion.move()
sealion.eats()
print(Aquatic.mro())