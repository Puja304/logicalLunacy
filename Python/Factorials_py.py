#Factorial

input_number = int(input("Enter the digit you want a facotorial for: "))
def factorial(initial_integer):
    if initial_integer == 1:
        return initial_integer
    else:
        return initial_integer * factorial(initial_integer-1)


if input_number < 0:
    print("Invalid Input")
elif input_number == 0:
    print("0! is 1")
else:
    print(str(input_number) + "! is " + str(factorial(input_number)))
    