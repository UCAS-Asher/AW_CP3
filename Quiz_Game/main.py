#Asher Wangia, Quiz Game
import csv
import random

print("This is a quiz game try to get the highest score possible!")

def main():
    print("""
    Quiz Game Choices
    1. Play Game
    2. Exit 
    """)

    main_choice = input("Choose a Number: ")

    if main_choice == "1":
        questions = get_questions()#Gets the questions from a csv
        game(questions)
        
        
    elif main_choice == "2":
        print("Thanks for Playing!")
    else:
        print("Not an Option. Try Again!")
        main()


def game(questions):
    score = 0

    for question in questions:
        answer = answer_question(question)
        score += answer

    print("You got a score of ",score, "/10")


def answer_question(question):
    answer = 0
    print(question["Question\n"])
    print("1.",question["Answers"][0], " 2.", question["Answers"][1])
    print("3.",question["Answers"][2], " 4.", question["Answers"][3])

    your_answer = input("Choose a Number: ")

    if your_answer == "1":
        if question["Answers"][0] == question["Correct Answer"]:
            answer +=1
    elif your_answer == "2":
        if question["Answers"][1] == question["Correct Answer"]:
            answer +=1
    elif your_answer == "3":
        if question["Answers"][2] == question["Correct Answer"]:
            answer +=1
    elif your_answer == "4":
        if question["Answers"][3] == question["Correct Answer"]:
            answer +=1
    else:
        print("Not an Option")
        answer_question(question)

    if answer > 0:
        print("You got the question right")
    else:
        print("You got the question wrong")

    


def get_questions():
    questions = []
    
    with open("Quiz_Game/math_questions.csv") as file:
        file = csv.reader(file)
        next(file)

        for row in file:
            question = {# Creates the question that will be displayed getting the correct answer and answer options from here
            "Question": row[0],
            "Correct Answer": row[4],
            "Answers": row[1:4]#Answer Options
            }
            random.shuffle(question["Answers"])# Shuffles the order of the Answers
            questions.append(question)# Adds the question to a list were the questions will be selected

    random.shuffle(questions)#Shuffles the order of the questions

    return questions

main()
