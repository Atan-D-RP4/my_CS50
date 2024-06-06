#include <stdio.h>

void swap(int* a, int* b);

int main(void)
{
    printf("No.of Elements to be Sorted:");
	int size; scanf("%d", &size);
	int N[size], min_index;

	for(int i = 0; i < size; i++)
	{
		scanf("%d", &N[i]);
	}

    for (int i = 0; i < size - 1; i++)
    {
        min_index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (N[j] > N[min_index])
            {
                    min_index = j;
            }

            if (min_index != i)
            {
                swap(&N[min_index], &N[i]);
            }
        }
     }

    for(int i = 0; i < size; i++)
	{
		printf("%d", N[i]);
	}
}

void swap(int *a, int *b)
{
   int temp = *a;
    *a = *b;
    *b = temp;

}