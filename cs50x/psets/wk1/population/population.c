#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    unsigned int n, i, j;
    do
    {
        n = get_int("Starting Pop: ");
    }
    while (n < 9);

    // TODO: Prompt for end size
    do
    {
        i = get_int("Final Pop: ");
    }
    while (n > i);

    // TODO: Calculate number of years until we reach threshold
    for (j = 0; n < i; j++)
    {
        int k = n;
        k = n + (n/3) - (n/4);
        n = k;
    }

    // TODO: Print number of years
    printf("Years: %d\n", j);
}


