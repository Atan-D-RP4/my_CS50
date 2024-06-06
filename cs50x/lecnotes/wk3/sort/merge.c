#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int usage(int argc, char* argv[]);
int* get_elements(int* arr, int size);
void show_elements(int* arr, int size);
void merge(int* arr, int size_main, int* left, int size_left, int* right, int size_right);
void merge_sort(int* arr, int size);

int main(int argc, char* argv[])
{
    if(usage(argc, argv) == 1)
        return 1;

    int size = atoi(argv[1]);
    printf("Enter Elements:\n");

    int* arr = NULL;
    arr = get_elements(arr, size);
    if (arr == NULL)
    {
        printf("Failed to allocate memory\n");
        return 1;
    }

    merge_sort(arr, size);

    show_elements(arr, size);
}

int usage(int argc, char* argv[])
{
    if (argc == 1)
    {
        printf("Usage: ./insert_sort [No.of elements]\n");
        return 1;
    }
    return 0;
}

int* get_elements(int* arr, int size)
{
    arr = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        printf("Element %d:", (i + 1));
        scanf("%d", &arr[i]);
    }

    return arr;
}

void show_elements(int* arr, int size)
{
     for (int i = 0; i < size; i++)
    {
        printf("Index %d: %d\n", (i + 1), arr[i]);
    }
    return;
}


void merge_sort(int* arr, int size)
{
    if (size > 1)
    {
        int mid = size / 2;
        int left[mid];
        int right[size - mid];

        for (int i = 0; i < size; i++)
        {
            if (i < mid)
                left[i] = arr[i];
            else
                right[i - mid] = arr[i];
        }

        merge_sort(left, mid);
        merge_sort(right, (size - mid));
        merge(arr, size, left, mid, right, (size - mid));

    }
    return;
}

void merge(int* arr, int size_arr, int* left, int size_left, int* right, int size_right)
{
    int i, j, k;
    for (i = 0, j = 0, k = 0; i < size_left && j < size_right;)
    {
        if (left[i] < right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
            k++;

    }

    for (; i < size_left; i++, k++)
        arr[k] = left[i];

    for (; j < size_right; j++, k++)
        arr[k] = right[j];

    return;
}