#include <stdio.h>
#include <cs50.h>

int main(void)
{
    char character = get_char("Character: ");
    printf("Ascii Value of Character: %i\n", character);
}