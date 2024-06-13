#Binary Search in an ordered list
ordered_list_numeric = [2,4,6,8,10,12,14,16,18,20]


def guess_the_secret(x):
    minimum = 1
    maximum = x
    feedback = ""
    count = 1
    print("Think of a number between the range 1 and the maximum you entered above. Enter S when you are done, and the computer will begin guessing")
    start = input()
    if start == 'S':
        while feedback != "c":
            computer_guess = ((maximum - minimum)//2) + minimum
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