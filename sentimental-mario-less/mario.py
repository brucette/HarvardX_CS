from cs50 import get_int

# Keep asking for integer between 1-8 if user enters something other than that
while True:
    height = get_int("Height:")
    if height > 0 and height < 9:
        break

# Set counter for second nested loop to go upwards
counter = 1

for i in range(height):
    for j in range(height - 1):
        print(" ", end="")

    for k in range(counter):
        print("#", end="")

    print()
    height -= 1
    counter += 1


