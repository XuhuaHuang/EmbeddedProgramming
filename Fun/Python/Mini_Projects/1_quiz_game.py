# Topic: Mini project - 1
# Quiz Game
# Ask user a question and record answers and scores
# Author: Xuhua Huang
#
# Last updated: June 10, 2021
# Created on: June 10, 2021

def main():
    # greet user
    print("Welcome to my computer quiz")
    # ask user whether to play the game
    playing: bool = eval(input('Do you want to play? Press 1 for YES and 0 for NO '))
    # handle playing variable
    if not playing:
        quit()
    else:
        print("Let's start!")

    score = 0
    # question 1 - CPU
    answer: str = input("What does the term 'CPU' stand for? ")
    if answer.lower() == "central processing unit":
        print("Correct!")
        score += 1
    else:
        print("Wrong answer! The correct answer is 'central processing unit'.")

    # question 2 - GPU
    answer: str = input("What does the term 'GPU' stand for? ")
    if answer.lower() == "graphics processing unit":
        print("Correct!")
        score += 1
    else:
        print("Wrong answer! The correct answer is 'graphics processing unit'.")

    # question 3 - RAM
    answer: str = input("What does the term 'RAM' stand for? ")
    if answer.lower() == "random access memory":
        print("Correct!")
        score += 1
    else:
        print("Wrong answer! The correct answer is 'random access memory'.")

    # question 4 - ROM
    answer: str = input("What does the term 'ROM' stand for? ")
    if answer.lower() == "read-only memory" or "read only memory":
        print("Correct!")
        score += 1
    else:
        print("Wrong answer! The correct answer is 'read-only memory'.")

    print(f"End of quiz. You got {score} questions correct!"
          f"Your score is {(score/4)*100}%.")


if __name__ == '__main__':
    main()