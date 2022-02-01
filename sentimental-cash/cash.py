from cs50 import get_float
import math

while True:
    amount = get_float("Amount: ")
    if amount > 0:
        break

# Number of coins
coins = 0

# Divide by 25 cents with truncation
quarters = int(amount * 100 / 25)

if quarters > 0:
    coins += quarters

# Divide by 10 cents
dimes = amount - quarters * 100 / 25

# Divide by 5 cents
nickels =

# Divide by 1 cents
pennies =

print(coins)