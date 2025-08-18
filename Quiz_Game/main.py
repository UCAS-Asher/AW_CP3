#Asher Wangia, Quiz Game
import csv
import time
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
        questions = get_questions(question_choice())#Gets the questions from a csv
        game(questions)   
    elif main_choice == "2":
        print("Thanks for Playing!")
    else:
        print("Not an Option. Try Again!")
        main()



def question_choice():# Gets the question set the user wants by returning diffrent csv file relative paths
    print("""
        Question Sets
        1. Math
        2. English
        """)

    choice = input("Choose a Number: ")

    if choice == "1":
        question_set = "Quiz_Game/math_questions.csv"
    elif choice == "2":
        question_set = "Quiz_Game/english_questions.csv"
    else:
        print("Not an Option. Try Again!")
        question_set = question_choice()

    return question_set



def game(questions):
    score = 0

    for question in questions[1:11]:#Gets first ten questions which are randomly decided
        answer = answer_question(question)
        score += answer

    print("You got a score of",str(score)+"/10\n")

    main()



def answer_question(question):
    answer = 0
    print(question["Question"],"\n")
    print("1.",question["Answers"][0], "  |   2.", question["Answers"][1])
    print("3.",question["Answers"][2], "  |   4.", question["Answers"][3])

    start_time = time().time()
    your_answer = input("Choose a Number: ")
    end_time = time().time()
    seconds = (end_time - start_time)

    if seconds < 5 and seconds > 4:#Timing for extra score
        pass
    elif seconds < 4 and seconds > 3:
        pass
    elif seconds < 3 and seconds > 2:
        pass
    elif seconds < 2 and seconds > 1:
        pass
    elif seconds < 1:
        pass

        

    if your_answer == "1":
        if question["Answers"][0] == question["Correct Answer"]:#Checks if answer option is correct and adds score if correct
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
        
    if answer > 0:
        print("You got the question right\n")
    else:
        print("You got the question wrong\n")
    
    return answer



def get_questions(question_set):
    questions = []
    
    with open(question_set) as file:
        file = csv.reader(file)
        next(file)

        for row in file:
            question = {# Creates the question that will be displayed getting the correct answer and answer options from here
            "Question": row[0],
            "Correct Answer": row[5],
            "Answers": row[1:5]#Answer Options
            }
            random.shuffle(question["Answers"])# Shuffles the order of the Answers
            questions.append(question)# Adds the question to a list were the questions will be selected

    random.shuffle(questions)#Shuffles the order of the questions

    return questions

main()
