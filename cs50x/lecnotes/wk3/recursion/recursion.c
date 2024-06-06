#include <stdio.h>
#include <cs50.h>

void build_pyramid(int n);

int main()
{
    int n;
    n = get_int("Height: ");
    build_pyramid(n);
}

void build_pyramid(int n)
{
    if(n <= 0)
    return;
    build_pyramid(n - 1);
    for(int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}