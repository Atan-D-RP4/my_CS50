#include <stdio.h>
#include <cs50.h>
#include <math.h>

void build_pyramid(int n);

int main()
{
    unsigned int n;
    do
   {
      label:
      n = get_int("Height: ");
      if(n == 0)
      {
      goto label;
      }
   }
   while (n > 8);

   build_pyramid(n);

}

void build_pyramid(int n)
{
    for(int i = 0; i <= n; i++)
    {
        for(int k = n; k >= 1 + i;  k--)
        {
            printf(" ");
        }
        for(int m = n; m >= n - i; m--)
        {
            printf("#");
        }
        printf(" ");
        for(int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}