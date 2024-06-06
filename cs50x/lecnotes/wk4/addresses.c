#include <stdio.h>
#include <cs50.h>

int main(void)
{
    char *s = "HI!"; string k = "YO!";
    printf("%s\n", s);
    printf("%s\n", s + 1);
    printf("%s\n", s + 2);
    printf("%s\n", s + 3);

    printf("%s - %p\n", k, k);
    printf("%c - %p\n", k[0], &k[0]);
    printf("%c - %p\n", k[1], &k[1]);
    printf("%c - %p\n", k[2], &k[2]);
    printf("%c - %p\n", k[3], &k[3]);
}