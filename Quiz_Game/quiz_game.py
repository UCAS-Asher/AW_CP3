#Asher Wangia, Quiz Game
import csv
import random


def main():
    print("""
    Quiz Game Choices
    1. Play Game
    2. Exit 
    """)

    main_choice = input("Choose a Number: ")

    if main_choice == "1":
        pass
    elif main_choice == "2":
        pass
    else:
        print("Not an Option. Try Again!")

def random_answers(questions):
    for question in questions:
        answers = question["Answers"]
        ran_answers = []
        for answer in answers:
            chosen = random.choice(answers)
            if chosen in ran_answers:
                pass
            else:
                ran_answers.append(chosen)
        


def get_questions():
    questions = []
    
    with open("Quiz_Game/questions.csv") as file:
        file = csv.reader(file)
        next(file)

        for row in file:
            question = {
            "Question": row[0],
            "Correct Answer": row[5],
            "Answers": row[1:5]
            }

        questions.append(question)

    return questions