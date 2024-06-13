import random

def guess(x):
    random_number = random.randint(1,x)
    best_guess = 0
    count = 0
    while random_number != best_guess:
        count += 1
        best_guess = int(input("Guess the number: "))
        print(best_guess)
        if best_guess < random_number:
            print(f"Sorry! {best_guess} is too low!")
        elif best_guess > random_number:
            print(f"Sorry! {best_guess} is too high")
    print(f"Congratulations! {best_guess} is the right answer! It took you {count} tries.")


guess(10000)