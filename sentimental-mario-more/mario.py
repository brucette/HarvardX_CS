from cs50 import get_int

# Keep asking for integer between 1-8 if user enters something other than that
while True:
    height = get_int("Height:")
    if height > 0 and height < 9:
        break

# Set counter for second nested loop to go upwards
counter = 1

for i in range(height):
    # Print left spaces
    for j in range(height - 1):
        print(" ", end="")

    # Print the left hashes
    for k in range(counter):
        print("#", end="")

    # Print middle spaces
    print("  ", end="")

    # Print the right hashes
    for l in range(counter):
        print("#", end="")

    print()
    counter += 1
    height -= 1



