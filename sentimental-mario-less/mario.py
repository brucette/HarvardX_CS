from cs50 import get_int

while True:
    height = get_int("Height:")
    if height > 0 and height < 9:
        break


for i in range(height - 1):
    print(".")

    for j in range(height):
        print("." * (height - 1), "#", end="")
        #print(, end="")
    print()
    height -= 1


