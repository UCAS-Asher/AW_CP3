#AW Student  Class


class Student:
    student_id: int
    student_name: str
    student_grade: float

    def __init__(self, student_id=000, student_name="John Doe", student_grade=100):
        self.student_id = student_id
        self.student_name = student_name
        self.student_grade = student_grade

    def get_students():
        pass

    def __str__(self):
        return f"Student ID: {self.student_id}, Name: {self.student_name}, Grade: {self.student_grade}"
    


def main():
    print("Choices\n1.Display Student Grades\n2.Modify Student Grades\n3.Exit")
    choice = input("Choose a Number: ")

    if choice == "1":
        pass
    elif choice == "2":
        pass
    elif choice == "3":
        print("Program End!")
    else:
        print("Not an Option!\n")
        main()

main()