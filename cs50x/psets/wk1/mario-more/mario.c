#include <stdio.h>

int main()

{
    // Prompt user for Height within range of {1,8}
    unsigned int n;
    do
    {
    label:
        printf("Height: ");
        scanf("%d", &n);
        if (n == 0)
        {
            goto label;
        }
    }
    while (n > 8);

    // For each row
    for (int i = n; i >= 1; --i)
    {
        // For each column
        for (int j = 2; j <= i; ++j)
        {

            // Position the Bricks
            printf(" ");
        }
        for (int k = n - i; k <= n; --k)
        {

            // Print the Brick
            printf("#");
        }
        printf("  ");
        for (int m = n - i; m <= n; --m)
        {

            // Print the Brick
            printf("#");
        }
        printf("\n");
    }
    return 0;
}
