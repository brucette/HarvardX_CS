from cs50 import get_float
import math

while True:
    amount = get_float("Amount: ")
    if amount > 0:
        break

# Convert amount to cents
amount *= 100

# Number of coins
coins = 0

# Divide by 25 cents with truncation
quarters = int(amount / 25)

if quarters > 0:
    coins += quarters

# Divide by 10 cents
dimes = amount / 10

# Divide by 5 cents
nickels = amount / 5

# Divide by 1 cents
pennies = amount / 1

print(coins)