#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main (void)
{
    string names[] = {"Carter", "David"};
    string numbers[] = {"+1-6175-495-1000", "+1-949-468-2750"};
    string name = get_string("Name: ");
    for(int i = 0; names[i] != (void *)0; i++)
    {
        if(strcmp(names[i], name) == 0)
        {
        printf("Found in %s\n", numbers[i]);
        return 0;
        }
    }
    printf("Not found\n");
    return 1;
}