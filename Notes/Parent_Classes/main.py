#AW Parent Classes


#What is a parent/abstract class?

#How do you create a child class?

#How does a child class inherit from the parent class?

#What are class diagrams?

#How are class diagrams used to show a parent/child relationship?

#How do you overload operators in a class?

#What are test cases?
    #

#Why do we use test cases?
    #To double check if the code still works

#How do we create test cases?
    #Seperate file in same folder test_filename.py or filename_test.py


class Animal():
    def __init__(self, age, color):
        self.age = age
        self.color = color

    def move(self):
        pass

    def __str__(self):
        return f"Age: {self.age}\nColor: {self.color}"
    
    def __eq__(self, other):
        return (self.age == other.age and self.color == other.color)
    
class Dog(Animal):
    def __init__(self, age, color, owner, breed, name):
        super().__init__(age, color)
        self.owner = owner
        self.breed = breed
        self.name = name

    def move(self):
        print(f"{self.name} runs")

    def __str__(self):
        return f"Name: {self.name}\nAge: {self.age}\nColor: {self.color}\nOwner: {self.owner}\nBreed: {self.breed}\n"
    
    def __eq__(self, other):
        return (self.age == other.age and
                self.color == other.color and
                self.owner == other.owner and
                self.breed == other.breed and
                self.name == other.name)
    
bobby = Dog(5, "brown", "Jill", "Bulldog", "Bobby")
birdy = Dog(1, "Black", "Nikkie", "Lab", "Birdy")
alex = Animal(16, "White")
nick = Animal(16, "White")

print(bobby.move())
print(alex)

print(alex==nick)
print(bobby==birdy)