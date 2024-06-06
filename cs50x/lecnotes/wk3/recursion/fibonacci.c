#include <stdio.h>
#include <cs50.h>

void fibonacci(int n);

int main (void)
{
    int terms = get_int("Number of terms: ");
    printf("%d %d ",0, 1);
    fibonacci(terms - 2);
    printf("\n");
}

void fibonacci(int n)
{
    if(n <= 0)
    return;

    static int n1 = 0, n2 = 1, n3;
    fibonacci(n - 1);
    n3 = n1 + n2;
    n1 = n2;
    n2 = n3;
    printf("%d ", n3);
}