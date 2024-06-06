#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    // Gets Cents
    int n;
    do
    {
        n = get_int("Cents Owed: ");
    }
    while (n <= 0);
    return n;
}

int calculate_quarters(int cents)
{
    // Calculates quarters owed
    int i, n = cents;
    for (i = 0; n >= 25; i++)
    {
        n = n - 25;
    }
    return i;
}

int calculate_dimes(int cents)
{
    // Calculates dimes owed
    int i, n = cents;
    for (i = 0; n >= 10; i++)
    {
        n = n - 10;
    }
    return i;
}

int calculate_nickels(int cents)
{
    // Calculates cents owed
    int i, n = cents;
    for (i = 0; n >= 5; i++)
    {
        n = n - 5;
    }
    return i;
}

int calculate_pennies(int cents)
{
    // Calculates pennies owed
    int i, n = cents;
    for (i = 0; n >= 1; i++)
    {
        n = n - 1;
    }
    return i;
}