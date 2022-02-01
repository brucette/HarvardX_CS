from cs50 import get_float

while True:
    amount = get_float("Amount: ")
    if amount > 0:
        break

# Divide by 25 cents
quarters = amount * 100 / 250
print(quarters)
# Divide by 10 cents
# Divide by 5 cents
# Divide by 1 cents