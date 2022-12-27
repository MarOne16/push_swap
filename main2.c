#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

void merge(int *arr, int low, int mid, int high, bool is_ascending)
{
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int left[n1], right[n2];

    for (i = 0; i < n1; i++)
        left[i] = arr[low + i];
    for (j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = low;
    while (i < n1 && j < n2)
    {
        if (is_ascending ? left[i] <= right[j] : left[i] >= right[j])
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

    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void bitonic_merge(int *arr, int low, int high, bool is_ascending)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        bitonic_merge(arr, low, mid, !is_ascending);
        bitonic_merge(arr, mid + 1, high, is_ascending);
        merge(arr, low, mid, high, is_ascending);
    }
}

void bitonic_sort(int *arr, int n)
{
    if (n > 1)
    {
        int mid = n / 2;
        bitonic_sort(arr, mid);
        bitonic_sort(arr + mid, n - mid);
        bitonic_merge(arr, 0, n - 1, true);
    }
}

int main()
{
    int arr[MAX_SIZE];
    int n = 0;
    printf("Enter a list of integers to be sorted, followed by EOF: ");
    while (scanf("%d", &arr[n]) != EOF)
        n++;

    bitonic_sort(arr, n);

    printf("Sorted list: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
