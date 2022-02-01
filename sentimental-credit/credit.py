from cs50 import get_string

# Get card number from user
card = get_string("Number: ")
length = len(card)


# Concatenate to new string every other digit of card, starting from second last
every_other = ""

i = length - 2
while i >= 0:
    every_other += card[i]
    i -= 2


# Multiply by 2 every digit in concatenated string
multiplied = ""

for digit in every_other:
    multiplied += str(int(digit) * 2)


# Sum of products of every other digit starting from second last multiplied by 2
sum = 0

for digit in multiplied:
    sum += int(digit)


# Sum of remaining numbers
sum_rest = 0

i = length - 1
while i >= 0:
    sum_rest += int(card[i])
    i -= 2


# Check if 0 exists in end sum by using % 10
if (sum_rest + sum) % 10 == 0:

    if card[0] == '4' and (length == 13 or 16):
        print("VISA\n")

    elif card[0] == '5' and card[1] >= '1' and card[1] <= '5' and length == 16:
        print("MASTERCARD\n")

    elif card[0] == '3' and card[1] == '4' or '7' and length == 15:
        print("AMEX\n")
else:
    print("INVALID\n")

