from cs50 import get_string

# Asking for input from user
text = get_string("Text: ")

# Defining a global variable to count letter, word and sentence
letter = 0
word = 1
sentence = 0

# Examine each character of the string
for i in range(len(text)):
    if text[i].isalpha() == True:
        letter += 1
    if text[i].isspace() == True and text[i+1].isspace() == False:
        word += 1
    if text[i] == "." or text[i] == "?" or text[i] == "!":
        sentence += 1

# Calculating grade
grade = round(0.0588 * (letter/word*100) - 0.296 * (sentence/word*100) - 15.8)

# Printing the result
if grade >= 16:
    print("Grade 16+")
elif grade <= 1:
    print("Before Grade 1")
else:
    print("Grade " + str(grade))