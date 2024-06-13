#Scheduling

import random
#For each emplyee, add which days they can work, and how many days a week will be working for.
#Step 1: Create lists for each day of the week listing which employees will be available
employee_name = ""
days_of_the_week = {"Sunday":"","Monday":"","Tuesday":"","Wednesday":"","Thursday":"","Friday":"","Saturday":""}
#Week = Sunday + Monday + Tuesday + Wednesday + Thursday + Friday + Saturday
while True:
    employee_name = input("Add name of the emplyee")
    if employee_name == "over":
        break
    availability = list(input("What is their availablity?: ").split(","))
    number_of_days = int(input("How many days a week can they work?"))
    for i in availability:
        if i in days_of_the_week:
            if len(days_of_the_week[i]) > 1:
                days_of_the_week[i] = str(days_of_the_week[i]) + ", " + employee_name
            else:
                days_of_the_week[i] = employee_name
    removed = []
    # for employees in days_available:
    if len(availability) > number_of_days:
        for k in range(len(availability) - number_of_days):
            removal = random.choice(availability)
            list_to_verify = list((days_of_the_week[removal]).split(", "))
            print(list_to_verify)
            while removal in removed and (len(list_to_verify) < 7 or len(removed) == len(availability - 1)):
                removal = random.choice(availability)
            removed.append(removal)
            days_of_the_week[removal] = days_of_the_week[removal].removesuffix(", " + employee_name)
            days_of_the_week[removal] = days_of_the_week[removal].removesuffix(employee_name)




for i in days_of_the_week:
    print(i + ": "+ days_of_the_week[i])
