from cs50 import get_string


card = get_string("Number: ")
length = len(card)

if length != 13 and length != 15 and length != 16:
    print("INVALID\n")
#print(length)

# String for every other digit starting from second last
every_other = ""

i = length -2
while i >= 0:
    every_other += card[i]
    i -= 2

#print(every_other)

# String for every other digit (from second last) multiplied by 2
multiplied = ""

for digit in every_other:
    multiplied += str(int(digit) * 2)

#print(multiplied)

# Sum of products of every other digit starting from second last multiplied by 2
sum = 0

for digit in multiplied:
    sum += int(digit)

#print(sum)

# Sum of remaining numbers
sum_rest = 0

i = length -1
while i >= 0:
    sum_rest += int(card[i])
    i -= 2


if (sum_rest + sum) % 10 == 0:

    if card[0] == '4' and (length == 13 or 16):
        print("VISA\n")

    elif card[0] == '5' and card[1] >= '1' and card[1] <= '5' and length == 16:
        print("MASTERCARD\n")

    elif card[0] == '3' and (card[1] == '4' or card[1] == '7') and length == 15:
        print("AMEX\n")
else:
    print("INVALID\n")

