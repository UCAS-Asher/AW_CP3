#AW Student  Class

class Student:
    def __init__(self, id="000", name="John Doe", grade=100):
        self.id = id
        self.name = name
        self.grade = grade

    def get_grade(self):
        return self.grade
        
    def set_grade(self, new_grade):
        self.grade = new_grade

    def __str__(self,):
        return f"Student ID: {self.id}, Name: {self.name}, Grade: {self.grade}"


#Creating 5 student objects
max = Student("001","Max Well")
bart = Student("002", "Bart Bort", 67)
bob = Student("003", "Bob Spore", 76)
mark = Student("004", "Mark Park", 87)
john = Student()

print("Initial Grades: ")#Print out each student's information
print(max)
print(bart)
print(bob)
print(mark)
print(john)

#Change Grades of 3 students
max.set_grade(67)
bart.set_grade(76)
bob.set_grade(67)

print("\nUpdated Grades:")#Display Newly changed Grades
print(f"{max.name}'s new grade: {max.get_grade()}")
print(f"{bart.name}'s new grade: {bart.get_grade()}")
print(f"{bob.name}'s new grade: {bob.get_grade()}")