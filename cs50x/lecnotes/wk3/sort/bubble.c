#include <stdio.h>

int main(void)
{
	int n; scanf("%d", &n);
	int N[n];
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &N[i]);
	}
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        if(N[j] > N[j + 1])
        {
            int temp = N[j];
            N[j] = N[j + 1];
            N[j + 1] = temp;
        }
        printf("%2d", N[i]);
    }
    printf("\n");
}