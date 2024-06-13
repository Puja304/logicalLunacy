import random
'''
def computer_guess():
    x = int(input("Your number will be in the range 1 to "))
    secret_number = int(input(f"Enter an integer between 1 and {x} "))
    computer_guess = 0
    count = 0
    maximum = x
    minimum = 1
    while computer_guess != secret_number:
        count += 1
        if computer_guess != 0:
            print(computer_guess)
        if computer_guess > secret_number:
            print(f"Sorry! {computer_guess} is too high!")
            maximum = computer_guess
            if minimum != 1:
                computer_guess = random.randint(minimum + 1,maximum -1)
            else:
                computer_guess = random.randint(minimum,maximum -1)
        elif computer_guess < secret_number:
            if computer_guess != 0:
                print(f"Sorry! {computer_guess} is too low!")
            minimum = computer_guess
            if maximum != x:    
                computer_guess = random.randint(minimum + 1, maximum - 1)
            else:
                computer_guess = random.randint(minimum + 1, maximum)
    print(f"Congratulations! {computer_guess} is the correct answer. It took you {count} tries. ")

    
computer_guess()
'''

def guess_the_secret(x):
    minimum = 1
    maximum = x
    feedback = ""
    count = 1
    print("Think of a number between the range 1 and the maximum you entered above. Enter S when you are done, and the computer will begin guessing")
    start = input()
    if start == 'S':
        while feedback != "c":
            computer_guess = random.randint(minimum, maximum)
            print(computer_guess)
            feedback = input("Is the guess too high(H), too low(L), or correct(C)?").lower()
            if feedback == "h":
                count += 1
                maximum = computer_guess - 1
            elif feedback == "l":
                count += 1
                minimum = computer_guess + 1    
        print(f"Well done, computer! It guessed your secret number {computer_guess} in {count} tries!")


max_range = int(input("The range of numbers you will select from is 1 to ____: "))
guess_the_secret(max_range)