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
dimes = (amount % 25) / 10

if dimes > 0:
    coins += dimes

# Divide by 5 cents
nickels = ((amount % 25) % 10) / 5

if nickels > 0:
    coins += nickels

# Divide by 1 cents
pennies = (((amount % 25) % 10) % 5) / 1

if pennies > 0:
    coins += pennies

print(int(coins))
print()