#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;
string deci_to_bin(int deci);
void print_bulb(int bit);

int main(void)
{
    string s = get_string("Message: "); // Get the Input String
    string bit;
    for (int i = 0; s[i] != '\0'; i++) // Iterate over each character of the string
    {
        int n = s[i];
        bit = deci_to_bin(n); // Convert the ASCII value of the character to a binary
        for (int j = 0; j < 8; j++) // Iterate over each digit of the bit
        {
            // Output the emoji
            if (bit[j] == '0')
            {
                print_bulb(0);
            }
            else
            {
                print_bulb(1);
            }
        }
        printf("\n");
    }

}


void print_bulb(int bit) // Converts the binary value to emoji
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}

string deci_to_bin(int deci) // Converts the Inputted decimal to binary
{
    static char bit[8];
    for (int i = 7; i >= 0; i--, deci /= 2)
    {
        if (deci % 2 == 0)
        {
            bit[i] = '0';
        }
        else
        {
            bit[i] = '1';
        }
    }

    return bit;
}