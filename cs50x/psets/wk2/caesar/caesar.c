#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

string cipher(string source, int k); // Encrypts the source text
bool digit(string text); // Checks whether inputted string contains only digit characters

int main(int argc, string argv[])           // Take only
{
    if (argc != 2 || digit(argv[1]) == 0)   // one command-line arguement
    {
        printf("Usage: ./caesar key\n");    // that is an integer
        return 1;
    }
    else
    {
        string source = get_string("plaintext:  "); // Get Plain text
        printf("ciphertext: %s\n", cipher(source, atoi(argv[1]))); // Output the Cipher text
        return 0;                           //     \    key    /
    }
}

string cipher(string source, int k)
{
    for (int i = 0; source[i] != '\0'; i++) // Iterate over each character of string
    {
        if (ispunct(source[i]) == 0)
        {
            if (islower(source[i]))
            {
                int p = source[i] - 96; // Converts ASCII character to alphabetical index
                p = (p + k) % 26; // Shifts aplhabetical index by formula and key
                source[i] = p + 64; // Converts aplhabatical index to ASCII character
                source[i] = tolower(source[i]); // Matches Case of character before and after shift
            }
            else if (isupper(source[i]))
            {
                int p = source[i] - 64; // Converts ASCII character to alphabetical index
                p = (p + k) % 26; // Shifts aplhabetical index by formula and key
                source[i] = p + 64; // Converts aplhabatical index to ASCII character
                source[i] = toupper(source[i]); // Matches Case of character before and after shift
            }
        }
    }
    return source; // Returns Encrypted string
}

bool digit(string text)
{
    for (int i = 0; text[i] != '\0'; i++) // Iterates over each character of string
    {
        if (isdigit(text[i]) == 0) // Returns false if character is not a digit character
        {
            return 0;
        }
    }
    return 1; // Returns true otherwise
}
