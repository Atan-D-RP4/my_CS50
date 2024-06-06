#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long ccn;
    do
    {
    ccn = get_long("Card Number: ");
    }
    while (ccn < 0);

    // Better Implementation of Luhn's Algorithm
    int sum = 0;
    for (int i = 0; ccn != 0; i++, ccn /= 10)
    {
        if(i % 2 == 0)
            sum += ccn % 10;
        else
        {
            int digit = (ccn % 10) * 2;
            sum += (digit % 10) + (digit / 10);
        }
    }
    printf("%i\n", sum);
}