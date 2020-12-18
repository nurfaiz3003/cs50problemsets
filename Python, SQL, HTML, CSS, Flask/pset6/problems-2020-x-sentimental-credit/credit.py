from cs50 import get_string

# Get user input
n = get_string("Number: ")
while n.isnumeric() == False:
    n = get_string("Number: ")

# Count Second to Last Digit to First
counter = 2
sum1 = 0
while len(n)/counter >= 1:
    digit = str(2 * int(n[len(n) - counter]))
    if len(digit) == 2:
        sum1 = sum1 + int(digit[0]) + int(digit[1])
        counter = counter + 2
    elif len(digit) == 1:
        sum1 = sum1 + int(digit)
        counter = counter + 2

# Count First to Last Digit to First
counter = 1
sum2 = 0
while len(n)/counter >= 1:
    sum2 = sum2 + int(n[len(n) - counter])
    counter = counter + 2

# Condition for Card Number
if (sum1+sum2) % 10 != 0:
    print("INVALID")

elif len(n) == 15 and (n[:2] == "37" or n[:2] == "34"):
    print("AMEX")

elif len(n) == 16 and (int(n[:2]) > 50 and int(n[:2]) < 56):
    print("MASTERCARD")

elif (len(n) == 16 or len(n) == 13) and (n[:1] == "4"):
    print("VISA")