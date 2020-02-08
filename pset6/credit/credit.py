import cs50
import math

# # Initialise variables
num = cs50.get_int("Credit Card Number: ")

cardType = "INVALID"
total = 0

numDigits = math.floor(math.log10(abs(num))) + 1
first = int(num / pow(10, numDigits - 2))

# Check if number passes formula

for i in range(0, numDigits):
    if (i % 2):
        d = int(num % 10 * 2)
        if (d > 9):
            d = d - 9
        total += int(d)
    else:
        total += int(num % 10)
    num = int(num / 10)

if (first >= 51 and first <= 55 and numDigits == 16 and total % 10 == 0):
    cardType = "MASTERCARD"
if ((first == 34 or first == 37) and numDigits == 15 and total % 10 == 0):
    cardType = "AMEX"
if (first >= 40 and first <= 49 and (numDigits == 13 or numDigits == 16) and total % 10 == 0):
    cardType = "VISA"
print(cardType)