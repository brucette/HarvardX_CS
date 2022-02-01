from cs50 import get_string


card = get_string("Number: ")
length = len(card)

if  length != 13 or length != 15 or length != 16:
    print("INVALID\n")
print(length)

# String for every other digit starting from second last
every_other = ""

for digit in range(length - 1, -2, 0):
    every_other  += digit

print(every_other)