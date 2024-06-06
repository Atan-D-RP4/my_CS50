#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool check_text(string source); // Checks if inputted string contains punctuations and has no repeating characters
string cipher(string plain, string key); // Encrypts inputted plain text

int main(int argc, string argv[])                   // Take only
{
    if (argc != 2)                                  // one command-line arguement
    {
        printf("Usage: ./substitution key\n");      // and remind user of
        return 1;
    }                                               // usage conditions
    else if (strlen(argv[1]) != 26 || check_text(argv[1]))
    {
        printf("Key must contain 26 unique alphabetical characters\n");
        return 1;
    }
    string plaintext = get_string("Plaintext: "); // Get Plain text
    printf("ciphertext: %s\n",  cipher(plaintext, argv[1])); // Output the Cipher text
    return 0;                                 //  \ key /
}


bool check_text(string source)
{
    for (int i = 0; source[i] != '\0'; i++) // Iterate over each character
    {
        if (ispunct(source[i])) // Check whether character is punctuation
        {
            return 1; // If so return true
        }
    }
    for (int i = 0; source[i] != '\0'; i++) // Iterate over each character
    {
        for (int n = 0; source[n] != '\0'; n++)
        {
            // Compare against every other character of the string
            if (i == n)
            {
                n++;
                if (n == 26)
                {
                    return 0;
                }
            }
            char x = tolower(source[i]), y = tolower(source[n]);
            if (x == y)
            {
                return 1;
            }
        }
    }
    return 0;
}

string cipher(string plain, string key)
{
    for (int i = 0; plain[i] != '\0'; i++) // Iterate over each character of string
    {
        if (ispunct(plain[i]) == 0)
        {
            if (islower(plain[i]))
            {
                int p = plain[i] - 97; // Converts ASCII character to alphabetical index
                plain[i] = key[p]; // Replace index value with character based on key
                plain[i] = tolower(plain[i]); // Matches Case of character before and after shift
            }
            else if (isupper(plain[i]))
            {
                int p = plain[i] - 65; // Converts ASCII character to alphabetical index
                plain[i] = key[p]; // Replace index value with character based on key
                plain[i] = toupper(plain[i]); // Matches Case of character before and after shift
            }
        }
    }
    return plain;
}