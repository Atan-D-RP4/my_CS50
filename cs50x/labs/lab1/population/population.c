#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int pop_start = 0;
    unsigned int pop_end = 0;
    do
    {
        pop_start = get_int("Starting Population: ");
    }
    while (pop_start < 9);

    // TODO: Prompt for end size
    do
    {
        pop_end = get_int("Target Population: ");
    }
    while (pop_end < pop_start);

    // TODO: Calculate number of years until we reach threshold
    int years, pop;
    for (years = 0, pop = pop_start; pop < pop_end; years++)
        pop += (pop / 3) - (pop / 4);

    // TODO: Print number of years
    printf("Years: %d\n", years);
}
