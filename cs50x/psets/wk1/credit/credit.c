#include <cs50.h>
#include <math.h>
#include <stdio.h>

// Function declarations
int ccn_len(long ccn);
void Show_Card_Brand(long ccn);
bool ccn_validity(long ccn);

int main(void)
{
    // Get Credit Card Number from the User as input
    long ccn;
    do
    {
        ccn = get_long("Card Number: ");
    }
    while (ccn < 0);

    // Checks the validity of the Card Number
    if (ccn_validity(ccn))
    {
        Show_Card_Brand(ccn);
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }
}

// Compute the Length of Card Number
int ccn_len(long ccn)
{
    int count;
    for (count = 0; ccn > 0; ccn /= 10, count++)
        ;
    return count;
}

// Finds the Brand of the Credit Card
void Show_Card_Brand(long ccn)
{
    if ((ccn >= 4e12 && ccn <= 5e12) || (ccn >= 4e15 && ccn <= 5e15))
    {
        printf("VISA\n");
    }
    else if ((ccn >= 34e13 && ccn <= 35e13) || (ccn >= 37e13 && ccn <= 38e13))
    {
        printf("AMEX\n");
    }
    else if (ccn >= 51e14 && ccn < 56e14)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

// Applies Luhn's Algorithm to Card Number
bool ccn_validity(long ccn)
{
    long ccn_tmp = ccn;
    int sum = 0;
    int digit = 0;

    for (int j = 0; ccn > 0; j++, ccn /= 10)
    {
        if (j % 2 == 0)
            sum += ccn % 10;
        else
        {
            digit = (ccn % 10) * 2;
            sum += (digit % 10) + (digit / 10);
        }
    }
    ccn = ccn_tmp;
    int card_len = ccn_len(ccn);
    return ((sum % 10 == 0) && ((card_len == 13) || (card_len == 15) || (card_len == 16)));
}
