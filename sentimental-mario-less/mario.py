from cs50 import get_int

while True:
    height = get_int("Height:")
    if height > 0 and height < 9:
        break

counter = 1

for i in range(height):
    for j in range(height - 1):
        print(" ", end="")

    for k in range(counter):
        print("#", end="")

    print()
    height -= 1
    counter += 1


