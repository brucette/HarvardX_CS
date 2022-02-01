from cs50 import get_string


card = get_string("Number: ")
length = len(card)

if  length != 13 or length != 15 or length != 16:
    print("INVALID\n")

# String for every other digit starting from second last

for i in range(length - 1, -2, 0):
    x += i