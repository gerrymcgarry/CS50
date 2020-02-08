# Recreates this half-pyramid using hashes from Nintendo’s Super Mario Brothers
import cs50
# Gets an integer between 0 and 8
while True:
    try:
        height = cs50.get_int("Height: ")
        if 1 <= height <= 8:
            break
    except ValueError:
        continue

# Displays the half Pyramid
for x in range(1, height+1):
    for y in range(height, 0, -1):
        if (y <= x):
            print("#", end='')
        else:
            print(" ", end='')
    print("  ", end='')
    for y in range(0, height, 1):
        if (y < x):
            print("#", end='')
    print("")