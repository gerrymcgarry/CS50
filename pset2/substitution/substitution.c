#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //Accept a single command-line argument, the key to use for the substitution. The key itself should be case-insensitive, so whether any character in the key is uppercase or lowercase should not affect the behavior of your program.
    //If your program is executed without any command-line arguments or with more than one command-line argument, your program should print an error message of your choice (with printf) and return from main a value of 1 (which tends to signify an error) immediately.
    //check if there are 2 arguments
    if (argc != 2)
    {
        printf("Usage: ./vigenere keyword\n");
        return (1);
    }
    //check if keyword is all letters
    int keyLen = strlen(argv[1]);
    printf("Length: %d", keyLen);
    // If your program is executed without any command-line arguments or with more than one command-line argument, your program should print an error message of your choice (with printf) and return from main a value of 1 (which tends to signify an error) immediately.
    // If the key is invalid (as by not containing 26 characters, containing any character that is not an alphabetic character, or not containing each letter exactly once), your program should print an error message of your choice (with printf) and return from main a value of 1 immediately.

    for (int i = 0; i < keyLen; i++)
    {
        if (!isalpha(argv[1][i]) || keyLen != 26)
        {
            printf("Usage: ./substitution keyword\n");
            return (1);
        }

        if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
        {
            argv[1][i] = argv[1][i] - 32;
        }
        for (int j = i + 1 ; j < keyLen; j++)
        {
            if (argv[1][i] == argv[1][j])
            {
                printf("Usage: ./substitution keyword\n");
                return (1);
            }
        }
    }
    printf("S - %s\n", argv[1]);
    //Your program must output plaintext: (without a newline) and then prompt the user for a string of plaintext (using get_string).
    string plaintext = get_string("plaintext: ");
    string ciphertext = plaintext;
    int strLen = strlen(plaintext);
    int j = 0;
    for (int i = 0; i < strLen; i++)
    {
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            ciphertext[i] = argv[1][toupper(plaintext[i]) - 65];
        }
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            ciphertext[i] = tolower(argv[1][toupper(plaintext[i]) - 65]);
        }

        if (plaintext[i] == ' ')
        {
            ciphertext[i] = ' ';
        }
    }
    // Your program must output ciphertext: (without a newline) followed by the plaintext’s corresponding ciphertext, with each alphabetical character
    // in the plaintext substituted for the corresponding character in the ciphertext; non-alphabetical characters should be outputted unchanged.
    // Your program must preserve case: capitalized letters must remain capitalized letters; lowercase letters must remain lowercase letters.
    // After outputting ciphertext, you should print a newline.
    printf("ciphertext: %s\n", ciphertext);
    // Your program should then exit by returning 0 from main.
    return (0);
}