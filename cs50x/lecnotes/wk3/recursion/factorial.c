#include <stdio.h>
#include <cs50.h>

int factorial(int n);

int main (void)
{
    int number = get_int("Number: ");
    printf("%d\n",factorial(number));
    return 0;
}

int factorial(int n)
{
    static int fact;
    if (n >= 1)
    {
        return fact = n * factorial(n - 1);
    }
    else
    {
        return 1;
    }
}