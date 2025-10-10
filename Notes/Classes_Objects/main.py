#AW Classes And Objects

#What is a class?

#What is an object?

#How is a class a form of encapsulation? 
    #It takes all the methods and puts them in one area

#How is a class an abstraction of an object?
    #it defines its general characteristics and behaviors

#How do you access information in an object?
    #object_name.variable_name

#How do you initialize a class?
    #do class className then put the init method inside

#How do you set a default value
    #in the init method set the values to something instead of just leaving them blank

#How do you use type hinting?
    # variable_name: data_type

#How do you set an attribute to be private?
    #put an underscore in front of a variable

#How do you make a class method?
    #define a function in a class

#Why do we include docstrings/
    #They document what is in the class and methods

#What does "self" do as a parameter for class methods?
    #It tells the method that just one object is being looked at

#What are getter and setter methods?
    #getter methods return something and setter methods change something

#What are magic methods?
    #a method that has two has two underscores at beggining and end are built in
#Where are class objects saved? (heap or stack?)
    #heap


class Person:
    """Person class with first and last names as well as age.
    Method to get full name, increase age by 1"""
    first_name: str
    last_name: str
    age: int
    def __init__(self, last_name, _first_name="John", age=0):
        self._first_name = _first_name
        self.last_name = last_name
        self.age = age

    def setAge(self):#setter method
        """Increase age by 1"""
        self.age +=1

    def full(self) -> str:#getter method
        """Create full name"""
        return self._first_name + " " + self.last_name
    
    def __str__(self):
        return f"First Name: {self._first_name}\nLast Name: {self.last_name}\nAge: {self.age}"

    

tia = Person("LaRose", "Tia", 28)
alex = Person("LaRose", "Alex", 37)
tia.setAge()

print(f"{tia.full()} age: {tia.age}")
print(f"{alex.full()} age: {alex.age}")