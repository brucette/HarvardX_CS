from cs50 import get_string


card = get_string("Number: ")
length = len(card)

if  length != 13 or length != 15 or length != 16:
    print("INVALID\n")
print(length)

# String for every other digit starting from second last
every_other = ""

i = length -2
while i >= 0:
    every_other += card[i]
    i -= 2

print(every_other)

# Sum of products of every other digit starting from second last
sum_every_other = 0

for digit in every_other:
    sum_every_other += int(digit)

print(sum_every_other)
