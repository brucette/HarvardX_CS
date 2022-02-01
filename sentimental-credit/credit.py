from cs50 import get_string


card = get_string("Number: ")
length = len(card)

if  length != 13 or length != 15 or length != 16:
    print("INVALID\n")
print(length)

# String for every other digit starting from second last
every_other = ""

for i in range(:length -2, -2, :):
    every_other += card[i]

print(every_other)