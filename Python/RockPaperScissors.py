#RockPaperScissors
import random
'''
picker = ["r","p","s"]
wins = ["rp", "ps","sr"]
ties = ["rr", "pp","ss"]

user_pick = ""
while user_pick != "q":
    comp_pick = random.choice(picker)
    user_pick = input("Pick rock(r), paper(p), or scissors(s). Press q to quit: ").lower()
    combo = comp_pick + user_pick
    if user_pick in picker:
        if combo in wins:
            print("You win!")
        elif combo in ties:
            print("It's a tie!")
        else:
            print("You lose!")
    elif user_pick != "q":
        print("Invalid input")
    
import random

def play():
    comp_pick = random.choice(["r","p","s"])
    print(comp_pick)
    user_pick = input("Enter rock(r), paper(p), or scissors(s): ").lower()

    if user_pick == comp_pick:
        return "It's a tie"

    if winner(comp_pick,user_pick) == True:
        return "You win!"

        
    return "You lose!"


def winner(comp_pick,user_pick):
    if (comp_pick == "r" and user_pick == "p") or (comp_pick == "p" and user_pick == "s") or (comp_pick == "s" and user_pick == "r"):
        return True

print(play())



practice_list = [15,2452,3456,426,5425,634,7348,8453,900,10]

def largest_in_list(number_list):
    if len(number_list) == 2:
        if number_list[0] >= number_list[1]:
            return number_list[0]
        else:
            return number_list[1]
    else:
        if number_list[0] < number_list[1]:
            return largest_in_list(number_list[1:])
        else:
            number_list[1] = number_list[0]
            return largest_in_list(number_list[1:])

print(largest_in_list(practice_list))

'''

import turtle
import random

def sqaure(size):
    color_list = ["red","blue","green","yellow","orange","pink","purple","brown"]
    turtle.fillcolor(random.choice(color_list))
    turtle.begin_fill()
    for i in range(4):
        turtle.forward(size)
        turtle.right(90)
    turtle.end_fill()

def turned(size):
    for i in range(size):
        sqaure(size)
        turtle.penup()
        turtle.left(360/size)
        turtle.pendown()
turned(60)