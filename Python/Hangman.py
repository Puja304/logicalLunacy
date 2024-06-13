#Hangman

import random
from eng_words_hangman import words
def hangman():
    secret_word = random.choice(words).upper()
    current_word = ("-"*len(secret_word))
    listed_word = list(current_word)
    lives = 6
    string_guessed = ""
    new_word = ""
    while secret_word != new_word:
        guessed = input("Guess a letter in the word: ").upper()
        if guessed not in string_guessed: 
            if guessed in secret_word:
                print(f"Your letter, {guessed}, is in the word")
                indices = []
                for i in range(len(secret_word)):
                    if secret_word[i] == guessed:
                        indices.append(i)
                for j in indices:
                    listed_word[j] = guessed
            else:
                print(f"Your letter, {guessed}, is not in the word")
                lives -= 1
        else:
            print(f"You have already guessed {guessed},trt another one.")
        print(f"You have {lives} lives left and the letters you have guessed are {string_guessed}")
        new_word = ""
        for i in listed_word:
            new_word += i
        print(f"Your current word is {new_word}")    
        if guessed not in string_guessed:
            string_guessed += guessed + " "
        if lives == 0:
            break
    
    if lives >= 1:
        print(f"Congratulations! You guesses the word {secret_word}!")
    else:
        print(f"You died. The word was {secret_word}")
        

hangman()