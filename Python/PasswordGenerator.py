#Password Generator
import string
import random
passwords = int(input("How many passwords would you like to generate?: "))
length_o_p = int(input("How long should the password(s) be?: "))
letters = list(string.ascii_letters)
numbers = list(string.digits)
symbols = ["!","@","#","$","%","&",",",".","?","^","*"]
all_char = letters + numbers + symbols

for i in range(passwords):
    a_password = ""
    for j in range(length_o_p):
        a_password += random.choice(all_char)
    print(a_password)
