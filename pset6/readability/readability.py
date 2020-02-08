# Computes the approximate grade level needed to comprehend some text
import cs50
import math

letters = 0
words = 1
sentences = 0
# Prompt the user for a string of text (using get_string).
text = cs50.get_string("Text: ")

# Loop through string one character at a time
for i in range(0, len(text)):
    # Count the number of letters, a letter is any lowercase character from a to z or any uppercase character from A to Z,
    if ((text[i] >= 'a' and text[i] <= 'z') or (text[i] >= 'A' and text[i] <= 'Z')):
        letters += 1
    # Count the number of words, any sequence of characters separated by spaces should count as a word
    if (text[i] == ' '):
        words += 1
    # Count the number of sentences in the text. any occurrence of a period, exclamation point, or question mark indicates the end of a sentence.
    if (text[i] == '.' or text[i] == '!' or text[i] == '?'):
        sentences += 1

# L is the average number of letters per 100 words in the text,
L = letters / (words / 100)
# S is the average number of sentences per 100 words in the text.
S = sentences / (words / 100)
# Coleman-Liau index
grade = 0.0588 * L - 0.296 * S - 15.8
print(letters)
print(words)
print(sentences)
if (grade >= 16):
    # If the resulting index number is 16 or higher, your program should output "Grade 16+"
    print("Grade 16+")
elif (grade < 1):
    # Your program should print as output "Grade X" where X is the grade level computed by the Coleman-Liau formula, rounded to the nearest integer.
    print("Before Grade 1")
else:
    # If the index number is less than 1, your program should output "Before Grade 1".
    print("Grade ",  round(grade))
