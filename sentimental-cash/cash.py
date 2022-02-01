from cs50 import get_float

while True:
    amount = get_float("Amount: ")
    if amount > 0:
        break

# Number of coins
coins = 0

# Divide by 25 cents with truncation
quarters = amount * 100 // 25
coins += quarters

# Divide by 10 cents
# Divide by 5 cents
# Divide by 1 cents
print(coins)