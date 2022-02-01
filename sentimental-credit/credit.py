from cs50 import get_string


card = get_string("Number: ")
length = len(card)

if len(card) != 13 or len(card) != 15 or len(card) != 16:
    print("INVALID\n")
print(length)

# String for every other digit starting from second last
every_other = ""

i = length -2
while i >= 0:
    every_other += card[i]
    i -= 2

print(every_other)

# String for every other digit (from second last) multiplied by 2
multiplied = ""

for digit in every_other:
    multiplied += str(int(digit) * 2)

print(multiplied)

# Sum of products of every other digit starting from second last multiplied by 2
sum = 0

for digit in multiplied:
    sum += int(digit)

print(sum)
