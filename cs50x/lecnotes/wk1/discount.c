#include <cs50.h>
#include <stdio.h>

float discount(float price, int percentage);

int main(void)
{
    float retail = get_float("Retail Price: \n");
    float percent_off = get_float("Percentage Off:\n");
    float sale = discount(retail, percent_off);
    printf("Sale Price: %.2f\n", sale);
}

float discount(float price, int percentage)
{
    return price = price * (100 - percentage) / 100;
}