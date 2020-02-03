import cs50

change = -1
while True:
    try:
        change = cs50.get_float("Change owed: ")
        if 0 <= change:
            break
    except ValueError:
        continue

cents = int(change * 100)
quarters = int(cents / 25)
cents = int(cents - quarters * 25)
dimes = int(cents / 10)
cents = int(cents - dimes * 10)
nickels = int(cents / 5)
cents = int(cents - nickels * 5)
pennies = int(cents)
total = quarters + dimes + nickels + pennies
print(int(total))