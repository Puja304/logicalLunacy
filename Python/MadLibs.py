#Mad Libs - take inputs from users and insert them into a pre-existing story
adjective1 = input("Adjective: ")
verb1 = input("Verb: ")
event = input("Event: ")
noun1 = input("Noun: ")
verb2 = input("Verb: ")
adjective2 = input("Adjective: ")
verb3 = input("Verb: ")
noun2 = input("Noun: ")


print((f"It was a {adjective1} day.The smell of {verb1} had made itslef home in the air, and it was impossible to feel it and not remember {event}. Days like these make you ask questions. What\
does it mean to {noun1}? Are we even {verb2}? Then you look up, and stare at the {adjective2} sky, and the sight makes you forget everything else. I {verb3} here, waiting for a {noun2},\
unaware that it will never come. Such is life."))


#new thing used = f strings
#put f before the inverted commas that indicate the beginning of a string. Then put curly brackets whenever you want to add a variable inside the string, and name the variable inside.
#variables must hold values outside the print statement in order for them to get assigned values that will then get printed. 