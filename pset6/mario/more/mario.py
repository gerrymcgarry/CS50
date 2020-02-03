# Recreates this half-pyramid using hashes from Nintendo’s Super Mario Brothers

# Gets an integer between 0 and 8
while True:
    try:
        height = input("Height: ")
        if 1 <= int(height) <= 8:
            break
    except ValueError:
        continue

# Displays the half Pyramid
for x in range(1, int(height)+1):
    for y in range(int(height), 0, -1):
        if (y <= x):
            print("#", end='')
        else:
            print(" ", end='')
    print("  ", end='')
    for y in range(0, int(height), 1):
        if (y < x):
            print("#", end='')
    print("")