#AW Student  Class

def is_numeric_string(variable):#Checks if the variable is a number
    try:
        int(variable)
        return True
    except ValueError:
        return False

class Student:
    student_id: int
    student_name: str
    student_grade: int
    students = []

    def __init__(self, student_id=000, student_name="John Doe", student_grade=100):
        self.student_id = student_id
        self.student_name = student_name
        self.student_grade = student_grade
        Student.students.append(self)#Adds the student to a list

    def get_students(students):
        pass
        

    def set_grade(self):
        new_grade = input(f"{self.student_name}'s New Grade(Type No To Skip): ")
        if is_numeric_string(new_grade) == True:
            new_grade = int(new_grade)
        elif new_grade != "No" and new_grade != "no":
            print("Not a Number")
        
        if is_numeric_string(new_grade) == True and new_grade <= 100 and new_grade >= 0:#Checks for valid grade change
            self.student_grade = new_grade
        elif new_grade == "No" or new_grade == "no":
            pass
        else:
            print("Not an Option!")
            Student.set_grade(self)




    def __str__(self,):
        return f"Student ID: {self.student_id}, Name: {self.student_name}, Grade: {self.student_grade}"


max = Student(0o1,"Max Well")
bart = Student(0o2, "Bart Bort", 67)
bob = Student(0o3, "Bob Spore", 76)
mark = Student(0o4, "Mark Park", 87)
john = Student()


def main():
    print("Choices\n1.Display Students\n2.Modify Student Grades\n3.Exit")
    choice = input("Choose a Number: ")

    if choice == "1":
        for student in Student.students:
            Student.get_students(student)
            print("\n")
        main()
    elif choice == "2":
        for student in Student.students:
            print(student.student_grade)
        for student in Student.students:
            Student.set_grade(student)
        print("\n")
        main()
    elif choice == "3":
        print("Program End!")
    else:
        print("Not an Option!\n")
        main()

main()