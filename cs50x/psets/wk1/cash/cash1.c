#include<stdio.h>
#include<cs50.h>
#include<math.h>

float getValue(void);
int coins(int cents);

int main(void)
{
     // Make sure the user prompts a valid value
    float owed = getValue();
    // Convert dollars to cents
    int cents = round(owed * 100);
    // Prints how many coins are needed, breaks line
    printf("%d\n", coins(cents));
}

float getValue(void)
{
    return 0;
}

int coins(int cents)
{
    return 0;
}